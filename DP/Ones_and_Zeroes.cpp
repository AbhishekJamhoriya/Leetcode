public:
    int dp[601][105][105];
   
    
    int solve(vector<pair<int,int>>&arr,int m,int n,int i,int k){
        if(i==k){
            return 0;
        }
        
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int a=0;
        if(m-arr[i].first>=0 && n-arr[i].second>=0){
        a=1+solve(arr,m-arr[i].first,n-arr[i].second,i+1,k);
        }
        int b=solve(arr,m,n,i+1,k);
        return dp[i][m][n]=max(a,b);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>arr(strs.size());
        memset(dp,-1,sizeof(dp));
       for(int i = 0; i < strs.size(); i++)
        {
            int count_0 = 0;
            
            int count_1 = 0;
            
            for(int j = 0; j < strs[i].size(); j++)
            {
                if(strs[i][j] == '0')
                {
                    count_0++;
                }
                else
                {
                    count_1++;
                }
            }
            
            arr[i] = {count_0, count_1};
        }
        return solve(arr,m,n,0,strs.size());
        
    }
