class Solution {
public:
    
   
    int minStartValue(vector<int>& nums) {
    
        //minimum running sum
        int running_sum=0;
        int sum=0;
        for(auto val:nums)
        {
            sum+=val;
            running_sum=min(sum,running_sum);
        }
        return 1- running_sum;
        
    }
};