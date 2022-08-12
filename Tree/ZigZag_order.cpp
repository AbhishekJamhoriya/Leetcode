/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode *>q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            while(n--){
                TreeNode *val=q.front();
                q.pop();
                temp.push_back(val->val);
                if(val->left){
                    q.push(val->left);
                    
                }
                if(val->right){
                    q.push(val->right);
                }
            }
            if(i%2!=0){
                reverse(temp.begin(),temp.end());
            }
            i++;
            ans.push_back(temp);
        }
        return ans;
    }
};
