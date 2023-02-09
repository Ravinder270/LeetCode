class Solution {
public:
    vector<int>dp;
    
    int recurs(vector<int>& nums,int i)
    {
        if(i>=nums.size())
            return 10000000;
        
        if(i==nums.size()-1)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int a=10000000;
        
         for(int k=1;k<=nums[i]&&k+i<nums.size();k++)
         {
               a=min(a,recurs(nums,k+i)+(1));
         }
           
        return dp[i]=a;
    }
    
    
    int jump(vector<int>& nums) {
            dp.resize(20001,-1);
        return recurs(nums,0);
    }

};