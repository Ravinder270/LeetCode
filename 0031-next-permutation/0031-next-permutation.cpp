class Solution {
public:
   
    void nextPermutation(vector<int>& nums) {
    int n=nums.size();
        int i,j;
    for(i=n-2;i>=0;i--)   // find the breaking point
    {
        if(nums[i]<nums[i+1])
        {
            break;
        }
    }
    if(i<0)  // if no breaking point,it means array is in descending order
    {
        reverse(nums.begin(),nums.end());
    }
    else     // find the element to be swapped with (next greater than i)
    {
        for(j=n-1;j>=0;j--)
        {
            if(nums[j]>nums[i])
            {
                break;
            }
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end()); //reverse in order to get the next smaller no.
    }
    }
};