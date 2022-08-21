 void dfs(vector<int>&ans,vector<bool>&visit,vector<int> adj[],int i){
        visit[i]=true;
        ans.push_back(i);
        for(auto it:adj[i]){
            if(visit[it]==false){
                dfs(ans,visit,adj,it);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
        dfs(ans,visited,adj,i);
            }
        }
        return ans;
        
    }
