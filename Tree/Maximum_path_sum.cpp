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
    int ans=INT_MIN;
    int solve(TreeNode *root){
        if(!root){
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        ans=max(ans,left+root->val);
        ans=max(ans,right+root->val);
        ans=max(ans,root->val+left+right);
        return max({0,root->val,root->val+left,root->val+right});
        
    }
    
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        solve(root);
        return ans;
    }
};
