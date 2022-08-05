class Solution {
public:
    
    int ch(string a, string b){
        int n=a.size();
        int m=b.size();
        for(int i=0;i<=n-m;i++){
            int j;
            for(j=0;j<m;j++){
                if(a[i+j]!=b[j]){
                    break;
                }
            }
            if(j==m){
                return 1;
            }
        }
        return 0;
    }
    
    int repeatedStringMatch(string a, string b) {
        string c=a;
        int ans=1;
        while(c.size()<b.size()){
            c+=a;
            ans++;
        }
        if(ch(c,b)){
            return ans;
        }
        if(ch(c+a,b)){
            return ans+1;
        }
        return -1;
    }
};
