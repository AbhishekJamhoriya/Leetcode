class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1;
        int last=-1;
        int i=0;
        int j=nums.size()-1;
        vector<int>ans;
        while(j>=i){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                start=mid;
                j=mid-1;
            }
            else if(target<nums[mid]){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        i=0;
        j=nums.size()-1;
          while(j>=i){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                last=mid;
                i=mid+1;
            }
            else if(target<nums[mid]){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return {start,last};
        
    }
};