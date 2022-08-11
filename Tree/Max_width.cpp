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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans=0;
        if(!root){
            return ans;
        }
        queue<pair<TreeNode *,unsigned long long >>q;
        q.push({root,0});
        while(!q.empty()){
            auto vl=q.front();
            int n=q.size();
            unsigned long long  mn=vl.second;
            while(n--){
            auto a=q.front();
                q.pop();
                unsigned long long  val=a.second-mn;
                if(a.first->left){
                    q.push({a.first->left,2*val+1});
                }
                if(a.first->right){
                    q.push({a.first->right,2*val+2});
                }
               ans=max(ans,a.second-mn+1); 
                // cout<<val<<" "<<endl;/
            }
            
            
        }
        return ans;
    }
};
