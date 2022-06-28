class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int mx=0;
        for(int i=0;i<n;i++){
            mx+=nums[i];
            ans=max(mx,ans);
            if(mx<0){
                mx=0;
            }
        }
        return ans;
    }
};