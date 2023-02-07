class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int ,int>mp;;
        int ll = 0;
        int ans = 0;
        for(int i = 0; i<fruits.size() ; i++){
            mp[fruits[i]]++;
            while(mp.size() > 2){
                mp[fruits[ll]]--;
                if(mp[fruits[ll]] == 0){
                    mp.erase(fruits[ll]);
                }
                ll++;
            }

            ans = max(ans , i - ll + 1);
        }

        return ans ;
    }
};