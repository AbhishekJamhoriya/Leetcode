class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<bool>path(numCourses,false);
        map<int,set<int>>mp;
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            vis[prerequisites[i][1]]++;
            mp[prerequisites[i][0]].insert(prerequisites[i][1]);
        }
        queue<int>q;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            path[a]=true;
           for(auto it:mp[a]){
               vis[it]--;
               if(vis[it]==0){
                   q.push(it);
                   path[it]=true;
               }
           } 
        }
        for(int i=0;i<path.size();i++){
            if(path[i]==false){
                return false;
            }
        }
        return true;
    }
};
