class Solution {
public:
    
 
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int n=ans.size()-1;
            vector<int>val=ans[n];
            if(intervals[i][0]<=val[1]){
                ans[n][1]=max(ans[n][1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
            
        }
        return ans;
    }
};