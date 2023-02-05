class Solution {
public:
    vector<int> findAnagrams(string s, string p){
        vector<int>s1hash(26,0);
        vector<int>s2hash(26,0);
        
        int s1len=s.size();
        int s2len=p.size();
        
        if(s1len<s2len)return {};
        
        vector<int>ans;
        int left=0;
        int right=0;
        
        //Precalculating first
        while(right<s2len)
        {
            s1hash[s[right]-'a']++;
            s2hash[p[right]-'a']++;
            right++;
        }
        
        right=right-1;
        
        while(right<s1len)
        {
            if(s1hash==s2hash)
                ans.push_back(left);
             right++;
            if(right!=s1len)
            {
                s1hash[s[right]-'a']++;
                s1hash[s[left]-'a']--;
                left++;
            }
            
           
        }
        return ans;
    }
};