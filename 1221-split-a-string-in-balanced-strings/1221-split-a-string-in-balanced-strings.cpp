class Solution {
public:
    int balancedStringSplit(string s) {
        
        int ans=0;
        int ctR=0;
        int ctL=0;
        for(auto ch:s)
        {
            if(ch=='R')ctR++;
            if(ch=='L')ctL++;
            
            if(ctR==ctL)
            {
                ans++;
                ctR=0;
                ctL=0;
            }
        }
        return ans;
    }
};