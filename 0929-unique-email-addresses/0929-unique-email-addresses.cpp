class Solution {
public:
    
    string improve(string s)
    {
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                continue;
            }
            else if(s[i]=='+')
            {
                break;
            }
            else 
            {
                temp+=s[i];
            }
        }
        return temp;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>mp;
        
        
   for(string &s:emails)
       {
       int pos = s.find("@");
    
    string left=s.substr(0,pos);//**********
    string part1=improve(left);
    //cout<<part1<<" ";   
    string part2 = s.substr(pos);
    string temp=part1+part2;
     cout<<temp<<endl;  
    mp[temp]++;   
        }
        return mp.size();
    }
};