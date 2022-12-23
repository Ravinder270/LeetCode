class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n= prices.size();
    if(n==1)
        return 0;
    
    // basically they will store the optimal sequence across these indices {0.....i} such that 
    //we get maximum profit
    vector<int> buy(n), sell(n);
    buy[0]= -prices[0];  //we are buying it
    buy[1]= max( -prices[1], buy[0]);  // we will buy on the 0th or 1st day , whoever is smaller
    
    sell[0]=0;   // we cant sell on day 0 ( since we have to buy something ist)
    sell[1]= max( buy[0]+prices[1], sell[0]);
    
    // now starting from 2nd day (actually 3rd) , we wil apply optimal selection to get maxprofit
    
    for( int i=2; i<n; i++){
        buy[i] = max( sell[i-2]- prices[i], buy[i-1]);
        sell[i] = max( buy[i-1] + prices[i], sell[i-1]);
    }
    
    return max( buy[n-1],  sell[n-1]);
}
    
};