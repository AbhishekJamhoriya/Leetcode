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
    

    TreeNode *solve(vector<int>preorder,int i,int n){
        if(i>n){
            return NULL;
        }
        
        TreeNode *head=new TreeNode(preorder[i]);
        int k=n+1;
        for(int j=i;j<=n;j++){
            if(preorder[j]>preorder[i]){
                k=j;
                break;
            }
        }
        head->left=solve(preorder,i+1,k-1);
        head->right=solve(preorder,k,n);
        return head;
        
        
        
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // vector<int>inorder=preorder;
        int n=preorder.size();
        // sort(inorder.begin(),inorder.end());
        
        return solve(preorder,0,n-1);
    }
};
