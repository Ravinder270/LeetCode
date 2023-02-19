class Solution {
public:
    vector<int> distributeCandies(int c, int n) {
        vector<int>ans(n,0);
        
        for(int i=0;c>0;i++)
        {
            ans[i%n]+=min(c,i+1);
            c=c-(i+1);
        }
        return ans;
    }
};