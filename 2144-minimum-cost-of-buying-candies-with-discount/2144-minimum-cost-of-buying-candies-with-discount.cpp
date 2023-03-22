class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        priority_queue<int>pq(cost.begin(),cost.end());
        
        int ct=0;
        int sum=0;
        for(int i=0;i<cost.size();i++)
        {
            int val=pq.top();
            pq.pop();
            
            ct++;
            if(ct<=2)sum+=val;
            else ct=0;
        }
        return sum;
    }
};