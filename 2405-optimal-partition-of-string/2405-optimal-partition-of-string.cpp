class Solution {
public:
    int partitionString(string s){
        
        set<char>se;
        int ct=0;
        for(int i=0;i<s.size();i++)
        {
            if(se.count(s[i]))
            {
                ct++;
                se.erase(se.begin(),se.end());
                                se.insert(s[i]);

            }
            else
            {
                se.insert(s[i]);
            }
        }
        return ct+1;
    }
};