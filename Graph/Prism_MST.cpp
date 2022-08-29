	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	

    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       
        // int ans=0;
        vector<int>dis(V,1e9);
        vector<bool>vis(V,false);
        set<pair<int,int>>s;
        s.insert({0,0});
        dis[0]=0;
        int ans=0;
       while(!s.empty()){
           auto it=*(s.begin());
           s.erase(it);
           vis[it.second]=true;
           int w=it.first;
           int u=it.second;
           ans+=w;
           for(int i=0;i<adj[u].size();i++){
               auto temp=adj[u][i];
               if(vis[temp[0]]){
                   continue;
               }
               if(dis[temp[0]]>temp[1]){
                   s.erase({dis[temp[0]],temp[0]});
                   dis[temp[0]]=temp[1];
                   s.insert({dis[temp[0]],temp[0]});
               }
           }
       }
        return ans;
    }
