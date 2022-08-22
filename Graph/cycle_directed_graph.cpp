  bool findcycle(int src,vector<bool>&stk,vector<bool>&vis,vector<int> adj[]){
        vis[src]=true;
        stk[src]=true;
        for(auto it:adj[src]){
            
                if(stk[it]){
                    return true;
                }
                if(!vis[it] && findcycle(it,stk,vis,adj)){
                    return true;
                
            }
        }
        stk[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
         vector<bool>vis(V,false);
         vector<bool>stk(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] && findcycle(i,stk,vis,adj) ){
                return true;
            }
        }
        return false;
    }
