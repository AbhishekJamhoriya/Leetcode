class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        string ans="";
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            ans=s[i];
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
               dp[i][i+1]=1; 
                ans=s.substr(i,2);
                cout<<ans;
            }
            else{
                dp[i][i+1]=0;
            }
            
        }
        for(int i=2;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(s[j]!=s[j+i] ){
                    
                    dp[j][j+i]=0; 
                }
                else{
                    if(dp[j+1][j+i-1]==1){
                        ans=s.substr(j,i+1);
                        dp[j][j+i]=1;
                    }
                    else{
                       dp[j][j+i]=0; 
                    }
                   
                }
            }
        }
        return ans;
        
        
    }
};
