	vector<int>parent;
    vector<int>rank;
    int find_set(int v){
        if(v==parent[v]){
            return v;
        }
        return parent[v]=find_set(parent[v]);
    }
    
    void union_set(int i,int j){
        int a=find_set(i);
        int b=find_set(j);
        if(a!=b){
            if(rank[a]<rank[b]){
                swap(a,b);
            }
            parent[b]=a;
            if(rank[a]==rank[b]){
                rank[a]++;
            }
        }
    }
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<V;i++){
            parent.push_back(i);
            rank.push_back(0);
            for(int j=0;j<adj[i].size();j++){
                auto temp=adj[i][j];
                // cout<<i<<" "<<temp[0]<<" "<<temp[1]<<endl;
                q.push({-1*temp[1],{temp[0],i}});
            }
        }
        int ans=0;
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int w=it.first;
            int u=it.second.first;
            int v=it.second.second;
            int a=find_set(u);
            int b=find_set(v);
            if(a!=b){
                union_set(a,b);
                ans+=-1*w;
            }
        }
        
        return ans;
    }
