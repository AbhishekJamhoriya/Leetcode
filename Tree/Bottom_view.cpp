 vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(!root){
            return ans;
        }
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node *temp=q.front().first;
            int i=q.front().second;
            q.pop();
            mp[i]=temp->data;
            if(temp->left){
                q.push({temp->left,i-1});
            }
            if(temp->right){
                q.push({temp->right,i+1});
            }
            
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
