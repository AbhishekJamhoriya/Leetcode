class Solution {
public:
    bool isAnagram(string s, string t) {
        int ans=s.size();
        unordered_map<char,int>mp;
        int n=s.size();
        int m=t.size();
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<m;i++){
            if(mp.find(t[i])!=mp.end()){
                if(mp[t[i]]==0){
                    return false;
                }
                mp[t[i]]--;
                ans--;
            }
            else
                return false;
        }
        if(ans==0){
            return true;
        }
        return false;
    }
};
