class Solution {
public:
    //sliding window
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        vector<int>occurrence(256,0);
        int ans=0;
        while(r<s.length())
        {
            occurrence[s[r]]++;
            //for repeating word
            //just increment the left pointer
            //and decrement that occurence of left
            //i.e. just shifting our sliding window now
            while(occurrence[s[r]]>1)
            {
                occurrence[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
    return ans;
    }
};