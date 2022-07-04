class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int arr[V+1];
	    arr[0]=0;
	    for(int i=1;i<=V;i++){
	        arr[i]=INT_MAX;
	    }
	    
	    for(int i=1;i<=V;i++){
	        for(int j=0;j<M;j++){
	            if(coins[j]<=i){
	                int val=arr[i-coins[j]];
	                if(val!=INT_MAX && val+1<arr[i]){
	                    arr[i]=val+1;
	                }
	            }
	        }
	    }
	    if(arr[V]==INT_MAX){
	        return -1;
	    }
	    return arr[V];
	} 
	  
};
