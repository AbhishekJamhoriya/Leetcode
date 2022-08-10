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
    
    static bool comp(const pair<int,int> &a,const pair<int,int> &b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        map<int,vector<pair<int,int>>>mp;
        queue<pair<TreeNode *,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto op=q.front();
            q.pop();
            vector<pair<int,int>>val;
            if(mp.find(op.second.first)==mp.end()){
                val.push_back({op.first->val,op.second.second});
                mp[op.second.first]=val;
            }
            else{
                val=mp[op.second.first];
                val.push_back({op.first->val,op.second.second});
                mp[op.second.first]=val;
            }
            if(op.first->left){
             q.push({op.first->left,{op.second.first-1,op.second.second+1}});   
            }
             if(op.first->right){
             q.push({op.first->right,{op.second.first+1,op.second.second+1}});   
            }
            
        }
        
        for(auto it:mp){
            vector<pair<int,int>>val=it.second;
           
            vector<int>temp;
            sort(val.begin(),val.end(),comp);
            for(auto i:val){
                temp.push_back(i.first);
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
};
