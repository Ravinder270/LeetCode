class Solution {
public:
    
    bool prefixsum(vector<int>&nums,int startvalue)
    {
        int sum=startvalue;
        bool flag=true;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum<1)
            {
                flag=false;
                break;
            }
        }
        return flag;
    }
    int minStartValue(vector<int>& nums) {
        
        int startvalue=0;
        for(int i=1;i<=10000;i++)
        {
            if(prefixsum(nums,i))
            {
                startvalue=i;
                break;
            }
        }
        return startvalue;
    }
};