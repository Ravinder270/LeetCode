class Solution {
public:
    int M=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > pq(nums.begin(),nums.end());
        
        //i am incrementing minimum every and after that taking the product
        while(k--)
        {
            int val=pq.top();
            pq.pop();
            val++;
            pq.push(val);
        }
        
        //product time:)
        long long int prod=1;
        while(!pq.empty())
        {
            int val=pq.top();
            pq.pop();
            prod=((prod%M)*(val%M))%M;
            prod%=M;
        }
        
        return prod%M;
    }
};