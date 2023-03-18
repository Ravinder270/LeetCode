class Solution {
public:
    int minOperations(vector<int>& nums) {
       if (nums.size() <= 1) {
            return 0;
        }

        int count = 0;
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (num == nums[i]) {
                count++;
                num++;
            } else if (num > nums[i]) {
                num++;
                count += num - nums[i];
            } else {
                num = nums[i];
            }
        }
        return count;
        
    }
};