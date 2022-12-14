class Solution {
public:
    //T.C--O(N)
    //S.C--O(N)
    int lengthOfLongestSubstring(string s) {
     vector<int> arr(256,-1);
     
        int maxlen=0,start=-1;
        
        for(int i=0;i<s.length();i++)
        {
            if(arr[s[i]]>start)
            {
                start=arr[s[i]];
            }
            
            arr[s[i]]=i;
            
            maxlen=max(maxlen,i-start);
        }
        return maxlen;
    
    }
};