class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>>r(numRows);
     if(numRows==0)return{};
        
     r[0].push_back(1);
       for(int i=1;i<numRows;i++)
       {
           r[i].push_back(1);
           for(int j=1;j<i;j++)
           {
               r[i].push_back(r[i-1][j]+r[i-1][j-1]);
           }
           r[i].push_back(1);
       }
    return r;
    }
};