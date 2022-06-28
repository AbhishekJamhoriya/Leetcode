class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
           return findMedianSortedArrays(nums2,nums1);
        }
        int n=nums1.size();
        int m=nums2.size();
        int start=0;
        int end=n;
        int mid=(n+m+1)/2;
        while(end>=start){
            
            int mid1=(start+end)/2;
            int mid2=mid-mid1;
            int x1=mid1==0?INT_MIN:nums1[mid1-1];
            int y1=mid2==0?INT_MIN:nums2[mid2-1];
            int x2=mid1==n?INT_MAX:nums1[mid1];
            int y2=mid2==m?INT_MAX:nums2[mid2];
            if(x1<=y2&& x2>=y1){
                if((n+m)%2==0){
                    double ans=(max(x1,y1)+min(x2,y2))/2.0;
                    return ans;
                }
                else{
                     
                    return max(x1,y1);
                }
            }
            else if(x1>y2){
                end=mid1-1;
            }
            else{
                start=mid1+1;
            }
            
        }
        return 0.0;
        
        
    }
};