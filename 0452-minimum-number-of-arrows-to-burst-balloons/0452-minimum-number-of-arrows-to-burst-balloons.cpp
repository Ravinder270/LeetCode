class Solution {
public:
     static bool cmp(vector<int>& a , vector<int>& b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end() , cmp);
        int i = 0 , cnt = 0;
        for(int i = 0 ; i < n ; i++){
            int v1 = nums[i][1];
            while(i+1 < n && v1 >= nums[i+1][0]){
                i++;
            }
            cnt++;
        }
        return cnt;
    }
};