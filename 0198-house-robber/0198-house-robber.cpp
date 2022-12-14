class Solution {
public:
    int rob(vector<int>& nums) {
       int even=0;
       int odd=0;
       int n=nums.size();
       
       for(int i=0;i<=n-1;i++)
       {
           if(i%2==0)
           {
               even+=nums[i];
               even=max(even,odd);
           }
           else
           {
               odd+=nums[i];
               odd=max(even,odd);
           }

       }
       return max(even,odd);

        
    }
};