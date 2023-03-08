class Solution {
public:
    int operation(string s)
    {
        if(s=="--X")return -1;
        else if (s=="++X")return 1;
        else if (s=="X++")return 1;
        else return -1;
    }
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(auto i:operations)
        {
            ans+=operation(i);
        }
        return ans;
    }
};