vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int i=A.size()-1;
    int j=B.size()-1;
    priority_queue<pair<int,pair<int,int>>>q;
    set<pair<int,int>>s;
    vector<int>ans;
    q.push({A[i]+B[j],{i,j}});
    s.insert({i,j});
   for(int i=0;i<C;i++){
        
            ans.push_back(q.top().first);
            auto a=q.top().second;
            
            q.pop();
            if(s.find({a.first-1,a.second})==s.end()){
               q.push({A[a.first-1]+B[a.second],{a.first-1,a.second}});
               s.insert({a.first-1,a.second});
            }
            if( s.find({a.first,a.second-1})==s.end()){
                q.push({A[a.first]+B[a.second-1],{a.first,a.second-1}});
                s.insert({a.first,a.second-1});
            }
            
        
       
        
    }
    return ans;
}
