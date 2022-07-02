class Solution {
public:
    
    
    vector<int>leftside(vector<int>height){
        stack<int>s;
        vector<int>left;
        int i=0;
        int n=height.size();
        while(i<n){
             while(s.size()&&s.top()<=height[i]){
                s.pop();
            }
            if(s.size()==0){
                left.push_back(-1);
                s.push(height[i]);
            }
            else{
                left.push_back(s.top());
                
            }
            
            i++;
            
        }
       
        return left;
    }
     vector<int> rightside(vector<int>height){
        stack<int>s;
        vector<int>right;
      
        int n=height.size()-1;
        while(n>=0){
             while(s.size()&&s.top()<=height[n]){
                s.pop();
            }
            if(s.size()==0){
                right.push_back(-1);
                s.push(height[n]);
            }
            else{
                right.push_back(s.top());
            }
           n--;
        }
          reverse(right.begin(),right.end());
          return right;
    }
    
    int trap(vector<int>& height) {
        vector<int>left=leftside(height);
        vector<int>right=rightside(height);
        
        int ans=0;
        int n=height.size();
        
        for(int i=0;i<n;i++){
            int mn=min(left[i],right[i]);
            if(mn>0){
                ans+=mn-height[i];
            }
        }
        return ans;
    
        
    }
};