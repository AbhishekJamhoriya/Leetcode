//Memoization
// class Solution {
// public:
//     int dp[13][10001];
//     int solve(vector<int>coins,int amount,int i){
//         if(i<0|| amount<0){
//             return INT_MAX-1;
//         }
//         if(amount==0){
//             return 0;
//         }
//         if(dp[i][amount]!=-1){
//             return dp[i][amount];
//         }
//         int val=-1;
//         if(coins[i]>amount){
//             int a=solve(coins,amount,i-1);
//             dp[i][amount]=val=a;
//         }
//         int a=1+solve(coins,amount-coins[i],i);
//         int b=solve(coins,amount,i-1);
//         dp[i][amount]=val=min(a,b);
//         return val;
        
//     }
    
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size()-1;
//         memset(dp,-1,sizeof(dp));
//         int val=solve(coins,amount,n);
//         if(val==INT_MAX-1){
//             return -1;
//         }
//         return val;
//     }
// };

//Tabulation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0||j==0){
                    if(j==0){
                        dp[i][j]=0;
                    }
                    else{
                      dp[i][j]=INT_MAX-1;  
                    }
                }
            }
        }
         for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }
        int val=dp[n][amount];
        if(val==INT_MAX-1){
            return -1;
        }
        return val;
    }
};
