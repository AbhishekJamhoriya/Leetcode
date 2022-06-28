class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mx=0;
        int mn=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]-mn>mx){
                mx=prices[i]-mn;
            }
            mn=min(mn,prices[i]);
        }
        return mx;
    }
};