class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         int ans = 0;
        for(auto c : nums) ans ^= c;    // xor-ing all elements of array
        return ans;
    }
};