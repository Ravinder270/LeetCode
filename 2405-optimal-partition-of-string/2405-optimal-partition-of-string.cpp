class Solution {
public:
    int partitionString(string s){
    
        int n=s.length();
        int cnt_l=1;
        set<char>se;
        int cnt_r=1;
        //first from left
        for(int i=0;i<n;i++)
        {
           if(se.count(s[i]))
           {
               cnt_l++;
               se.clear();
               se.insert(s[i]);

           }
            
            else
            {
                se.insert(s[i]);
            }
        }
        
        se.clear();
        //second from right
        for(int i=n-1;i>=0;i--)
        {
           if(se.count(s[i]))
           {
               cnt_r++;
               se.clear();
               se.insert(s[i]);

           }
            
            else
            {
                se.insert(s[i]);
            }
        }
        
        return min(cnt_l,cnt_r);
    }
};