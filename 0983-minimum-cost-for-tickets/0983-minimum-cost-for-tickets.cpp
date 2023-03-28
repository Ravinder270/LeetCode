class Solution {
public:
    //1.Tabulation
    int solve(int n,vector<int>&days,vector<int>&cost)
    {
        vector<int>dp(n+1,INT_MAX);
        
        dp[n]=0;
        
        for(int k=n-1;k>=0;k--)
        {
            //1-day cost
            int option1= cost[0]+dp[k+1];
        
        //2-day cost
        //1.Take index to the desired location
        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++);
        
        //main thing
        int option2=cost[1]+ dp[i];
        
        //option 3
        for(i=k;i<n && days[i]<days[k]+30;i++);
        
        int option3=cost[2] + dp[i];
        
        
        dp[k]=min(option1,min(option2,option3));
        
        }
        
        
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        //vector<int>dp(days.size(),-1);
        return solve(days.size(),days,cost);
    }
};