class Solution {
public:
    int repeatedNTimes(vector<int>& nums){
        
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;   
        }
        int n;
        if(nums.size()%2==0)
            n=nums.size()/2;
        else
            n=nums.size()/2+1;
        for(auto it:mp)
        {
            if(it.second==n)
                return it.first;
        }
        return -1;
    }
};