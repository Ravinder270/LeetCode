class Solution {
public:
    //Brute force approach
    int minTimeToVisitAllPoints(vector<vector<int>>& A) {
     int cur_X=A[0][0];
     int cur_Y=A[0][1];
     
      int count=0;  
     for(int i=1;i<A.size();i++)
     {
         int destX=A[i][0];
         int destY=A[i][1];
         while(cur_X!=destX ||cur_Y!=destY)
         {
             if(cur_X<destX)cur_X++;
             else if(cur_X>destX)cur_X--;
             
             if(cur_Y<destY)cur_Y++;
             else if(cur_Y>destY)cur_Y--;
             
             count++;
         }
     }
        return count;
        
    }
};