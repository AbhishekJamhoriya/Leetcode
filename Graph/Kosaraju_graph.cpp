	void dfs(vector<int> adj[],int i,stack<int>&s,vector<bool>&vis){
	    vis[i]=true;
	    for(auto it:adj[i]){
	        if(!vis[it]){
	            dfs(adj,it,s,vis);
	        }
	    }
	    s.push(i);
	}
	void rdfs(vector<int> adj[],int i,vector<bool>&vis){
	    
	    vis[i]=true;
	    for(auto it:adj[i]){
	        if(!vis[it]){
	            rdfs(adj,it,vis);
	        }
	    }
	   
	}
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int>s;
        vector<bool>vis(V,false);
        vector<int>graph[V];
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,s,vis);
            }
        }
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                graph[it].push_back(i);
            }
        }
        vector<bool>vis1(V,false);
        int ans=0;
        while(!s.empty()){
            int temp=s.top();
            s.pop();
            if(!vis1[temp]){
                ans++;
                rdfs(graph,temp,vis1);
            }
        }
        return ans;
        
    }
