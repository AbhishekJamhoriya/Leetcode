class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>q;
        int m=n-k+1;
        for(int i=0;i<n;i++){
            q.push(nums[i]);
            if(q.size()>m){
                q.pop();
            }
        }
        cout<<q.top();
        int ans= q.top();
        return ans;
    }
};