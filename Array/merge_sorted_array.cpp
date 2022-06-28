class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int interval=m+n-1;
        int start=m-1;
        int end=n-1;
        while(start>=0 && end>=0){
            if(nums1[start]>=nums2[end]){
                nums1[interval]=nums1[start];
                start--;
            }
            else{
                 nums1[interval]=nums2[end];
                end--;
            }
            interval--;

        }
        while(end>=0){
            nums1[interval]=nums2[end];
                end--;
            interval--;
        }
    }
};