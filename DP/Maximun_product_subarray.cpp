class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=nums[0];
        int mn=nums[0];
        int ans=mn;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                swap(mn,mx);
            }
            mx=max(nums[i],mx*nums[i]);
            mn=min(nums[i],mn*nums[i]);
            ans=max({ans,mx,mn});
        }
        return ans;
    }
};
