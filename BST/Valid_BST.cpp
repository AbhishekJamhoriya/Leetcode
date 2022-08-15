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
    
    bool solve(TreeNode *root,long long left,long long right){
        if(root->val<=left || root->val>=right){
            return false;
        }
        if(root->left){
            if(!solve(root->left,left,root->val)){
                return false;
            }
        }
        if(root->right){
            if(!solve(root->right,root->val,right)){
                return false;
            }
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        
        return solve(root,LLONG_MIN,LLONG_MAX);
        
    }
};
