class Solution {
public:
     int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size(), mod = 1000000007;
        if(n == 1) return (nums[0]+k) % mod;
        long long int ans = 1;
        for(int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }
        while(k)
        {
            int val = pq.top();
            pq.pop();
            int nxt = pq.top();
            nxt = nxt-val;
            int mn = min(k, nxt+1);
            val += mn;
            pq.push(val);
            k -= mn;
        }
        while(!pq.empty())
        {
            ans = (ans*pq.top())%mod;
            pq.pop();
        }
        return ans;
        }
};