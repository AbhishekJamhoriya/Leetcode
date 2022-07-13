class MinStack {
public:
    long long  mn=INT_MAX;;
    stack<long long>ans;
    MinStack() {
        while (ans.empty() == false) ans.pop();
      mn = INT_MAX;
    }
    
    void push(int value) {
        long long val = value;
        if(ans.empty()){
           ans.push(val);
            mn=val;
        }
        else if(val>=mn){
            ans.push(val);
            
        }
        else{
            
            
            ans.push(2*val*1LL-mn);
            mn=val;
        }
    }
    
    void pop() {
        if(ans.top()<=mn){
            mn=2*mn-ans.top();
        }
        ans.pop();
       
    }
    
    int top() {
        if(ans.empty()){
            return -1;
        }
        long long tp=ans.top();
        if(tp<mn){
            return mn;
        }
        return tp;
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */