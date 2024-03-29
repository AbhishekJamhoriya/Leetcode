 int dp[101][101];
    int solve(int arr[],int i,int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
    }
