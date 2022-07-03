class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train wait
    
    int findPlatform(int arr[], int dep[], int n)
    {
    sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	
    	int ans=1;
    	int count=1;
    	int i=1;
    	int j=0;
    	while(i<n && j<n-1){
    	    
    	    if(arr[i]<=dep[j]){
    	        i++;
    	        count++;
    	    }
    	    else{
    	        count--;
    	        j++;
    	    }
    	    
    	    ans=max(ans,count);
    	}
    	return ans;
    	
    }
};