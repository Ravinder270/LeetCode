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
       int x = 0;
        for(auto s : operations)
            if(s[1] == '-') x--;
            else x++;
        return x;
    }
};