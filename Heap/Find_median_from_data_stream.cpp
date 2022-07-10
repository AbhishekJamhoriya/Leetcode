class MedianFinder {

public:
    
   
    
    
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>>mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.size()==0 || mx.top()>num){
            mx.push(num);
        }
        else{
            mn.push(num);
        }
        
        if(mx.size()>mn.size()+1){
            mn.push(mx.top());
            mx.pop();
        }
        if(mn.size()>1+mx.size()){
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if(mx.size()==mn.size()){
            if(mx.size()==0){
                return 0.0;
            }
            double ans=double(mx.top()+mn.top())/2.0;
            return ans;
        }
        else if(mx.size()>mn.size()){
            return double(mx.top());
        }
        return double(mn.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */