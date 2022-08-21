  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        vector<int>ans;
         queue<int>q;
       q.push(0);
       ans.push_back(0);
       while(!q.empty()){
           int a=q.front();
           q.pop();
           for(auto it:adj[a]){
               if(visited[it]==false){
                   q.push(it);
                   ans.push_back(it);
                   visited[it]=true;
               }
           }
       }
        return ans;
    }
