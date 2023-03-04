class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk){
        long  si=0;
        long  minm=-1;
        long  maxm=-1;
        long  result=0;
        
        for(int i=0;i<nums.size();i++)
        {
            //invalid conditions
            if(nums[i]<mink || nums[i]>maxk)
            {
              si=i+1;
              minm=-1;
              maxm=-1;  
            }
            
            if(nums[i]==mink)minm=i;
            if(nums[i]==maxk)maxm=i;
            
            result += max(0L, min(minm, maxm) - si + 1);
        }
        return result;
    }
};