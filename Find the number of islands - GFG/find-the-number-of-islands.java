//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++) {
                String[] S = br.readLine().trim().split(" ");
                for (int j = 0; j < m; j++) {
                    grid[i][j] = S[j].charAt(0);
                }
            }
            Solution obj = new Solution();
            int ans = obj.numIslands(grid);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


class pair{

    int first;

    int second; 

 public pair(int row,int col){

    first=row;

        second=col;

    }

}

 

class Solution {

   void bfs(int row, int col, int[][] vis, char[][] grid){

       vis[row][col]=1;

       Queue<pair> q = new LinkedList<>();

       q.add(new pair(row,col));

       while(q.size()>0){

         row= q.peek().first;

       col = q.peek().second;

        q.remove();

        // it is for traversing for neighbor

        for(int delrow=-1;delrow<=1;delrow++){

            for(int delcol =-1;delcol<=1;delcol++){

                int newrow =delrow+row;

                int newcol = delcol+col;

                if(newrow>=0 && newcol>=0 && newrow<grid.length && 

                newcol<grid[0].length && vis[newrow][newcol]==0&&grid[newrow][newcol]=='1' ){

                    vis[newrow][newcol]=1;

                    q.add(new pair(newrow,newcol));

                }

            }

        }

       }

       

   }

    

 public int numIslands(char[][] grid) {

       int count=0;

        int n =grid.length;

        int m = grid[0].length;

         int[][] vis = new int[n][m];

        for(int row=0; row<n; row++){

            for(int col =0; col<m; col++){

                if(grid[row][col]=='1' &&vis[row][col]==0){

                    bfs(row,col,vis,grid);

                    count++;

                }

            }

        }

       return count; 

    }

}