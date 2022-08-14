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
    
    TreeNode *find(TreeNode *root){
        if(!root){
            return NULL;
        }
        TreeNode *pre=root;
        while(pre->right){
            pre=pre->right;
        }
        return pre;
    }
    
    TreeNode *solve(TreeNode *root){
        if(!root){
            return NULL;
        }
        TreeNode *left=solve(root->left);
        TreeNode *right=solve(root->right);
        TreeNode *left_end=find(left);
        if(left){
            root->right=left;
            
            if(left_end){
                left_end->right=right;
            }
            // cout<<left->val<<" "<<right->val<<" "<<left_end->val<<" "<<root->val<<endl;
        }
        root->left=NULL;
        return root;
        
    }
    void flatten(TreeNode* root) {
        root=solve(root);
        // return ans;
    }
};
