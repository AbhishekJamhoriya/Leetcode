class Solution {
public:
    int dp[501][501];
    int solve(string a,string b,int i,int j){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]){
            return dp[i][j]=solve(a,b,i-1,j-1);
        }
        int p=solve(a,b,i,j-1);
        int q=solve(a,b,i-1,j);
        int r=solve(a,b,i-1,j-1);
        // cout<<p<<" "<<q<<" "<<r<<" "<<i<<" "<<j<< endl;
        return dp[i][j]=1+min({p,q,r});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size()-1;
        int m=word2.size()-1;
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,n,m);
        
    }
};
