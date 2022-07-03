class Solution
{
    public:
    static bool comp(Item a,Item b){
        double x=(double)a.value/(double)a.weight;
        double y=(double)b.value/(double)b.weight;
        return x>y;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double ans=0;
        int total=W;
        for(int i=0;i<n;i++){
            if(total>=arr[i].weight){
                ans+=arr[i].value;
                total-=arr[i].weight;
            }
            else{
                double r=(double)arr[i].value/(double)arr[i].weight;
                ans+=total*r;
                break;
            }
        }
        return ans;
    }
        
};
