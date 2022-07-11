class Solution {
public:
    
    vector<int>greater(vector<int>nums){
        vector<int>ans;
        stack<int>s;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                ans.push_back(-1);
                s.push(nums[i]);
            }
            else{
                while(!s.empty() && nums[i]>=s.top()){
                    s.pop();
                }
                if(s.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top());
                }
                s.push(nums[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr=greater(nums2);
        unordered_map<int,int>mp;
        int n=nums2.size();
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(arr[mp[nums1[i]]]);
        }
        return ans;
    }
};