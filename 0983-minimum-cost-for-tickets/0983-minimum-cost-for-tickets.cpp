class Solution {
public:
    //1.Recursion
    int solve(int n,int index,vector<int>&days,vector<int>&cost,vector<int>&dp)
    {
        //Base Case
        if(index>=n)return 0;
        
        if(dp[index]!=-1)return dp[index];
        //1-day cost
        int option1= cost[0]+solve(n,index+1,days,cost,dp);
        
        //2-day cost
        //1.Take index to the desired location
        int i;
        for(i=index;i<n && days[i]<days[index]+7;i++);
        
        //main thing
        int option2=cost[1]+ solve(n,i,days,cost,dp);
        
        //option 3
        for(i=index;i<n && days[i]<days[index]+30;i++);
        
        int option3=cost[2] + solve(n,i,days,cost,dp);
        
        
        dp[index]=min(option1,min(option2,option3));
        
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        vector<int>dp(days.size(),-1);
        return solve(days.size(),0,days,cost,dp);
    }
};