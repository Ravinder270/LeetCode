class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=-1;
        for(int i=0;i<word.length();i++)
        {
            if(ch==word[i])
            {
                index=i;
                break;
            }
        }
        if(index==-1)return word;
        else
        {
            int i=0;
            int j=index+1;
            string ans="";
            while(j--)
            {
                ans+=word[j];
            }
            while(index+1<word.length())
            {
                ans+=word[index+1];
                index++;
            }
              return ans;
            
        }
      
    }
};