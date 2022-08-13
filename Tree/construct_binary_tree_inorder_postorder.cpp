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
    
    int find(vector<int>inorder,int i,int n,int a){
        for(;i<=n;i++){
            if(inorder[i]==a){
                return i;
            }
        }
        return n+1;
    }
    
    TreeNode *solve(vector<int>preorder,int prestart,int preend,vector<int>inorder,int instart,int inend){
        if(inend<instart||prestart>preend){
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[prestart]);
        int index=find(inorder,instart,inend,preorder[prestart]);
        int ind=inend-index;
        root->left=solve(preorder,prestart+1+ind,preend,inorder,instart,index-1);
        root->right=solve(preorder,prestart+1,preend+ind,inorder,index+1,inend);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int n=inorder.size()-1;
        reverse(postorder.begin(),postorder.end());
        TreeNode *ans=solve(postorder,0,n,inorder,0,n);
        return ans;
    }
};
