class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        vector<int>result;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            //not found
           if(mp.find(target - nums[i])==mp.end())
           {
               mp[nums[i]]=i;
           }
           else
           {
               result.push_back(mp[target - nums[i]]);
               result.push_back(i);
           } 

        }
        return result;        
    }
};