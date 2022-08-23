	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>topo(V,0);
	    for(int i=0;i<V;i++){
	        for(auto j:adj[i]){
	            topo[j]++;
	        }
	    }
	    vector<bool>vis(V,false);
	    queue<int>q;
	    vector<int>ans;
	    for(int i=0;i<V;i++){
	        if(topo[i]==0){
	            q.push(i);
	            vis[i]=true;
	            ans.push_back(i);
	        }
	    }
	    
	   
	    while(!q.empty()){
	        int i=q.front();
	        q.pop();
	        for(auto j:adj[i]){
	            topo[j]--;
	            if(topo[j]==0){
	              vis[j]=true;
	              q.push(j);
	              ans.push_back(j);
	            }
	        }
	    }
	    return ans;
	    
	}
