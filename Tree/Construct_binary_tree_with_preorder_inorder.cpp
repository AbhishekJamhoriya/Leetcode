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
    
   unordered_map<int,int>mp;
    
    
    TreeNode *solve(vector<int>preorder, vector<int>inorder,int i,int j,int k){
        
        if( k>=inorder.size()){
            return NULL;
        }
        if(j<i || i>=inorder.size()){
            return NULL;
        }
        
        int index=mp[preorder[k]];
        // cout<<index<<" "<<k<<endl;
        TreeNode *temp=new TreeNode(preorder[k]);
        temp->left=solve(preorder,inorder,i,index-1,k+1);
        int leftnode=index-i;
        temp->right=solve(preorder,inorder,index+1,j,leftnode+k+1);
        return temp;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        
        TreeNode *ans=solve(preorder,inorder,0,n-1,0);
        return ans;
    }
};
