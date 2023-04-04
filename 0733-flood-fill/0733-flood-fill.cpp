class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&image,vector<vector<int>>&ans,int deltarow[],int deltacol[],int color,int inicolor)
    {
       ans[row][col]=color;
        
        int n=image.size();
        int m=image[0].size();
        
        for(int i=0;i<4;i++)
        {
            int nrow = row + deltarow[i];
            int ncol = col + deltacol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] ==inicolor && ans[nrow][ncol]!=color)
            {
                dfs(nrow,ncol,image,ans,deltarow,deltacol,color,inicolor);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int inicolor = image[sr][sc];
        
        
        vector<vector<int>>ans=image;
        
        int deltarow[]={-1,0,1,0};
        int deltacol[]={0,1,0,-1};
        
        dfs(sr,sc,image,ans,deltarow,deltacol,color,inicolor);
    
        return ans;
    }
};