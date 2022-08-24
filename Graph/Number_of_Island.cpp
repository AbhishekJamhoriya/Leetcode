class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m){
        grid[i][j]='0';
        if(i>0 && grid[i-1][j]=='1'){
            dfs(grid,i-1,j,n,m);
        }
        if(i<n-1 && grid[i+1][j]=='1'){
            dfs(grid,i+1,j,n,m);
        }
        if(j>0 && grid[i][j-1]=='1'){
            dfs(grid,i,j-1,n,m);
        }
        if(j<m-1 && grid[i][j+1]=='1'){
            dfs(grid,i,j+1,n,m);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return ans;
    }
};
