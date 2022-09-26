
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int ans=0;
	    vector<int>val(n,0);
	    
	    ans=arr[0];
	    for(int i=0;i<n;i++){
	        val[i]=arr[i];
	    }
	    for(int i=1;i<n;i++){
	       
	        for(int j=i-1;j>=0;j--){
	            
	            if(arr[i]>arr[j]){
	                val[i]=max(val[i],arr[i]+val[j]);
	                ans=max(ans,val[i]);
	               // break;
	            }
	        }
	       // cout<<val[i]<<" ";
	    }
	    return ans;
	}  
