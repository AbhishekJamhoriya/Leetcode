class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
       int i;
       for(i=n-2;i>=0;i--){
           if(nums[i+1]>nums[i]){
               break;
           }
           
       } 
       if(i<0){
           sort(nums.begin(),nums.end());
       }
        else{
            int k;
            for(k=n-1;k>i;k--){
                if(nums[k]>nums[i]){
                    break;
                }
            }
            swap(nums[k],nums[i]);
            sort(nums.begin()+i+1,nums.end());
        }
        
        
    }
};