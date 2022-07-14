class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        queue<pair<int,int>>q;
        int val=0;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    
                    continue;
                }
                else if(grid[i][j]==2){
                    // two++;
                    q.push({i,j});
                }
                else{
                   val++;  
                }
               
            }
        }
        if(val==0){
            return 0;
        }
        int ans=0;
        while(!q.empty()){
            int i=q.size();
            while(i--){
                auto a=q.front();
                int x=a.first;
                int y=a.second;
                q.pop();
                if(y-1>=0 && dp[x][y-1]==0 && grid[x][y-1]==1){
                    dp[x][y-1]=1;
                    q.push({x,y-1});
                    val--;
                }
                if(y+1<m && dp[x][y+1]==0 && grid[x][y+1]==1){
                     dp[x][y+1]=1;
                    q.push({x,y+1});
                    val--;
                }
                if(x-1>=0 && dp[x-1][y]==0 && grid[x-1][y]==1){
                     dp[x-1][y]=1;
                    q.push({x-1,y});
                    val--;
                }
                if(x+1<n && dp[x+1][y]==0 && grid[x+1][y]==1){
                     dp[x+1][y]=1;
                    q.push({x+1,y});
                    val--;
                }
                 // cout<<x<<" "<<y<<" "<<q.size()<<endl;
            }
           
            ans++;
        }
        if(val==0){
            return ans-1;
        }
        return -1;
    }
};