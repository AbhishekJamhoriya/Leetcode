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
    
    bool solve(TreeNode *left,TreeNode *right){
        if(!left &&!right){
            return true;
        }
        else if(!left &&right){
            return false;
        }
        else if(!right &&left){
            return false;
        }
        else if(left->val!=right->val){
            return false;
        }
        bool a=solve(left->left,right->right);
        bool b=solve(left->right,right->left);
        cout<<a<<" "<<b<<endl;
        return a&b;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        
        bool right=solve(root->left,root->right);
       
        return right;
    }
};
