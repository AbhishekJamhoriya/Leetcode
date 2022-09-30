class Solution {
public:

    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        sum=sum/2;
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=sum;i++){
            dp[0][i]=INT_MAX-1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];      
                }
                else{
                   dp[i][j]=min(dp[i-1][j],1+dp[i-1][j-nums[i-1]]); 
                }
            }
        }
        if(dp[n][sum]==INT_MAX-1){
            return false;
        }
        return true;
        
    }
};
