public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int solve(int n,int k){
        if(n==1){
            return k;
        }
        if(k==1 || k==0){
            return k;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            int a=solve(n-1,i-1);
            int b=solve(n,k-i);
            int c=max(a,b)+1;
            dp[n][k]=ans=min(ans,c);
        }
        return ans;
    }
    
    int eggDrop(int n, int k) 
    {   memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
