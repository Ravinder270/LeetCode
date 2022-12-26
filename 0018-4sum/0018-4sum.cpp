class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(ll i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])continue;       //REMOVES DUPLICATE IN 1ST INDEX
            ll t=target-nums[i];
            for(ll j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;     //REMOVE DUPLICATE IN 2ND INDEX
                ll s=t-nums[j];
                ll left=j+1,right=nums.size()-1;
                while(left<right){
                    ll sum=nums[left] + nums[right];
                    if(sum==s){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<nums.size()-1 && nums[left]==nums[left+1])left++;     //REMOVE DUPLICATE IN 3RD INDEX
                        while(right>0 && nums[right]==nums[right-1])right--;       //REMOVE DUPLICATE IN 4TH INDEX
                        left++;
                        right--;
                    }
                    else if(sum<s)left++;
                    else right--;
                }
            }
        }
        return ans;
    }
};