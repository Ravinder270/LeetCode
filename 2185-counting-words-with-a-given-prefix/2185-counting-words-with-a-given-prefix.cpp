class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        
        for(int i=0;i<words.size();i++)
        {
            if(words[i].length()>=pref.length())
            {
                bool flag=true;
                for(int j=0;j<pref.length();j++)
                {
                    if(pref[j]!=words[i][j])
                    {
                        flag=false;
                    }
                }
                
                if(flag)count++;
                
            }
            else
            {
                continue;
            }
        }
        return count;
    }
};