class Solution {
public:
    int lengthOfLongestSubstring(string s) {
                unordered_set<char>st;
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
           
             if(st.size()>0 && st.find(s[j])!=st.end()){
                while(st.find(s[j])!=st.end()){
                    st.erase(s[i]);
                    i++;
                }
                st.insert(s[j]);
               
            }
            else{
                 
                st.insert(s[j]);
                ans=max(ans,j-i+1);
                
            }
            j++;
        }
        return ans;
    }
};