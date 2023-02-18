class Solution {
public:
    string reverseOnlyLetters(string s) {
       string ans="";
       string helper="";
       for(int i=0;i<s.length();i++)
       {
           if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
           {
               helper+=s[i];
           }
       }
        
       int i=0;
       int j=helper.size()-1;
       while(i<s.size() || j>=0)
       {
           if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
           {
               ans+=helper[j];
               i++;
               j--;
           }
           else
           {
               ans+=s[i];
               i++;
           }
       }
        return ans;
           
    }
};