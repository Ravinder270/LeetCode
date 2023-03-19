class Solution {
    using vi = vector<int>;
    vi d1 = {1,2,-1,1,-2,-2,-1,2};
    vi d2 = {2,1,2,-2,1,-1,-2,-1};
public:
    int valid(int x, int y, int n){
        if(x>=0 and y>=0 and x<n and y<n) return 1;
        return 0;
    }
    
    void solve(int x, int y, int cur, vector<vi>&grid, vector<vi>&vis, int n, int &count){
        vis[x][y] = 1;
        for(int i=0;i<8;i++){
            int nx = x+d1[i];
            int ny = y+d2[i];
         if(valid(nx,ny,n) and !vis[nx][ny] and grid[nx][ny] == cur+1){
             count++;
             solve(nx,ny,cur+1,grid,vis,n,count);
           }
        }
    }
        bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size(),count=1;
        vector<vi>vis(n,vi(n,0));
        solve(0,0,0,grid,vis,n,count);
        return count==n*n;
    }
};