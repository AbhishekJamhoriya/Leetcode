class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        for(int i=1;i<n;i++){
            A[i]=A[i]+A[i-1];
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(A[i])==mp.end()){
                mp[A[i]]=i;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
           if(A[i]==0){
                ans=max(ans,i+1);
            }
            else  if(mp.find(A[i])!=mp.end()){
                ans=max(ans,i-mp[A[i]]);
            }
        }
        return ans;
        
    }
};
