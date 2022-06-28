class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp.insert(nums[i]);
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-1)==mp.end()){
                int val=1;
                int temp=nums[i]+1;
                while(mp.find(temp)!=mp.end()){
                    temp++;
                    val++;
                }
                ans=max(ans,val);
                
            }
        }
        return ans;
    }
};