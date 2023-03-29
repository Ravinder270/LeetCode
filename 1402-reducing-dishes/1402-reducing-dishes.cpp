class Solution {
public:
   
   int solve(vector<int> & a, int ind,int cnt,vector<vector<int>>& dp){
        if(ind >= a.size()){
            return 0;
        }
        if(dp[ind][cnt]!=-1){
            return dp[ind][cnt];
        }
        int take = (a[ind]*cnt) + solve(a,ind+1,cnt+1,dp);
        int notTake = solve(a,ind+1,cnt,dp);
        return dp[ind][cnt] = max(take,notTake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(satisfaction,0,1,dp);
    }
};