class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       map<int,int>mp;
        
        for(int i:nums)
        {
            mp[i]++;
        }
        
        vector<int>v;
        for(auto it:mp)
        {
            while(it.second!=0)
            {
                v.push_back(it.first);
                it.second--;
            }
        }
        return v;
    }
};