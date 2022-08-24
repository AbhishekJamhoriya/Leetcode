class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>col(n,-1);
        vector<bool>vis(n,false);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(vis[i]){
                continue;
            }
            else{
                 col[i]=0;
        vis[i]=true;
        q.push(i);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto it:graph[a]){
                if(col[a]==col[it]){
                    // cout<<a<<" "<<it;
                    return false;
                }
                if(vis[it]==false){
                    q.push(it);
                    col[it]=1-col[a];
                    vis[it]=true;
                }
            }
        }  
            }
        }
        return true;
     
    }
};
