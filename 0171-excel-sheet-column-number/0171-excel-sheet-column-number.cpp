class Solution {
public:
    
    
    int titleToNumber(string s) {
        
        int result = 0;
        for(char c : s)
        {
			//d = s[i](char) - 'A' + 1 (we used  s[i] -  'A' to convert the letter to a number like it's going to be C)

            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
        
    }
};