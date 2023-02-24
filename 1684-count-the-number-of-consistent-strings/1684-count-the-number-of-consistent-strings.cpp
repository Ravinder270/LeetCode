class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s;
        
        for(auto i:allowed)
        {
            s.insert(i);
        }
        int count=0;
        bool flag=true;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                if(s.find(words[i][j])==s.end())
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)count++;
            flag=true;
        }
        return count;
    }
};