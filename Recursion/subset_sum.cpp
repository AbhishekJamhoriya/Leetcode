class Solution
{
public:
    vector<int>ans;
    void solve(vector<int> arr, int sum,int i,int n){
        if(i>=n){
            ans.push_back(sum);
            return ;
        }
       
        solve(arr,sum+arr[i],i+1,n);
        solve(arr,sum,i+1,n);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
    
        int sum=0;
        solve(arr,sum,0,N);
        return ans;
    }
};