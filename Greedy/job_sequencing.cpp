class Solution 
{
    public:
    static bool comp(Job a,Job b){
        
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        vector<int>val(n,-1);
        int ans=0;
        int totaljob=0;
        for(int i=0;i<n;i++){
            int j=arr[i].dead-1;
            if(j>n){
                j=n;
            }
            while(j>=0 && val[j]!=-1){
                j--;
            }
            if(j>=0 && val[j]==-1 ){
                val[j]=arr[i].profit;
                ans+=arr[i].profit;
                // cout<<val[i]<<" ";
                totaljob++;
            }
        }
        return {totaljob,ans};
        
    } 
};