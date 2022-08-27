	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>ans(V,1e9);
        set<pair<int,int>>s;
        s.insert({0,S});
        ans[S]=0;
        while(!s.empty()){
            auto temp=*(s.begin());
            s.erase(temp);
            for(auto it:adj[temp.second]){
                if(ans[it[0]]>temp.first+it[1]){
                    s.erase({ans[it[0]],it[0]});
                    s.insert({temp.first+it[1],it[0]});
                    ans[it[0]]=temp.first+it[1];
                }
            }
        }
        return ans;
    }
