public:
    // Function to detect cycle in an undirected graph.
    
    bool findcycle(int src,int par,vector<bool>&vis,vector<int> adj[]){
        vis[src]=true;
        for(auto it:adj[src]){
            if(it!=par){
                if(vis[it]){
                    return true;
                }
                if(!vis[it] && findcycle(it,src,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] && findcycle(i,-1,vis,adj) ){
                return true;
            }
        }
        return false;
    }
