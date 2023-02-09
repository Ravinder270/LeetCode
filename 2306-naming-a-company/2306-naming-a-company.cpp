class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();

        // According to condition 1
        /*Group idea by their first letter and store their suffixes.
            eg - a - pple , bout , mount
                 b - at , oat
                 ...... till z
        */
        unordered_set<string> suffixGroup[26];
        for(int i=0 ; i<n ; i++){
            string word = ideas[i];
            suffixGroup[word[0]-'a'].insert(word.substr(1));
        }

       
        long long count=0;
        for(int i=0 ; i<25 ; i++){
            for(int j=i+1 ; j<26 ; j++){
                int common=0;
                for(auto suf : suffixGroup[i]){
                    if(suffixGroup[j].count(suf)){
                        common++;
                    }
                }
                count+= (suffixGroup[i].size() - common) * (suffixGroup[j].size() - common) * 2;
            }
        }
        return count;
    }
};