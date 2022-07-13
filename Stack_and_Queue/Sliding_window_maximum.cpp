class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(q.empty()){
                q.push_back(i);
            }
            else{
                
                while(!q.empty() && nums[q.back()]<nums[i]){
                    q.pop_back();
                }
                q.push_back(i);
            }
           
            if(i+1>=k){
                 // cout<<q.front()<<" ";
                while(!q.empty() && (i-q.front()+1)>k){
                    q.pop_front();
                }
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
        
    }
};