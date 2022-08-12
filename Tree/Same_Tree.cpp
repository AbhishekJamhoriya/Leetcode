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
    bool ans=true;
    void solve(TreeNode *p,TreeNode *q){
        if(!p && !q){
            return;
        }
        else if(p &&q){
            solve(p->left,q->left);
        
       
        solve(p->right,q->right);
        
        if(p->val!=q->val){
            ans=false;
        }
        }
        else{
           ans=false;
            return ;
        }
     
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        ans=true;
        solve(p,q);
        return ans;
    }
};
