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
    
    vector<long>solve(TreeNode *root,long &ans){
        if(!root){
            return {0,INT_MAX,INT_MIN};
        }
        vector<long>left=solve(root->left,ans);
        vector<long>right=solve(root->right,ans);
        if(root->val>left[2]&&root->val<right[1]){
            long val=left[0]+right[0]+root->val;
            ans=max(ans,val);
            return {val,min((long)root->val,left[1]),max((long)root->val,right[2])};
            
        }
        return {INT_MIN,INT_MAX,INT_MIN};
    }
    
    int maxSumBST(TreeNode* root) {
        long ans=0;
        solve(root,ans);
        return int(ans);
    }
};
