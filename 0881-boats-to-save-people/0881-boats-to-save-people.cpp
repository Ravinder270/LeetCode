// 1. sort the people array
// 2. set i =0 and j = n-1
// 3. traverse and check the sum of people[i] and people[j] is less than or equal to limit 
// if true {
//     count++;
//     j--;
//     i++;
// }
// else{
// //assign boat to j and reduce j
//     count++; j--;
// }
// TC - O(n logn)
// SC - O(1)

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      
        sort(people.begin(),people.end());
        int n=people.size();
        int i=0;
        int ans=0;
        int j=n-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                ans++;
                j--;
            }
        }
        return ans;
    }
};