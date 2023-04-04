class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
       int peri=0;
        int n=grid.size();
        int m=grid[0].size();
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[0].size();j++)
           {
               if(grid[i][j]==0)continue;
               
               peri+=4;
               if(i>0)peri-=grid[i-1][j];
               if(j>0)peri-=grid[i][j-1];
               if(i<n-1)peri-=grid[i+1][j];
               if(j<m-1)peri-=grid[i][j+1];
                   
           }
       }
        return peri;
    }
};