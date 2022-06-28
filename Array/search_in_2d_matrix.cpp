class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int c=matrix[0].size()-1;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            int a=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
                     if(a<=c && matrix[i][a]==target){
                return true;
            }
        }
        return false;
        
    }
};