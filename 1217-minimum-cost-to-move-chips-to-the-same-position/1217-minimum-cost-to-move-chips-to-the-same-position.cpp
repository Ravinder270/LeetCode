class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0;
        int even=0;
        for(auto i:position)
        {
            if(i%2==0)even++;
            else odd++;
            
        }
        if(odd>even)return even;
        return odd;
    }
};