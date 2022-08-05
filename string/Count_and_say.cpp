class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s="11";
        
        for(int i=2;i<n;i++){
            string val="";
            s+='&';
            int count=1;
            for(int j=1;j<s.size();j++){
                if(s[j]!=s[j-1]){
                    val=val+to_string(count)+s[j-1];
                    count=1;
                }
                else{
                    count++;
                }
            }
            // cout<<val<<" ";
            s=val;
            
        }
        return s;
    }
};
