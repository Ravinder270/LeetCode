//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            int[][] grid = new int[n][n];
            for(int i = 0; i < n; i++){
                String[] S = br.readLine().trim().split(" ");
                for(int j = 0; j < n; j++){
                    grid[i][j] = Integer.parseInt(S[j]);
                }
            }
            Solution obj = new Solution();
            boolean ans = obj.is_Possible(grid);
            if(ans)
                System.out.println("1");
            else 
                System.out.println("0");
        }
    }
}
// } Driver Code Ends


class Solution{

    public boolean is_Possible(int[][] grid){

        int n=grid.length;

        Queue<Integer> q=new LinkedList<>();

        for(int i=0;i<n;i++)

            for(int j=0;j<n;j++)

                if(grid[i][j]==1){

                    q.add(i*10+j);

                    break;

                }

         while(!q.isEmpty()){

             int loc=q.remove();

             int x,y;

             x=loc/10;

             y=loc%10;

             if(x!=0){

                 if(grid[x-1][y]==2)

                    return true;

                 if(grid[x-1][y]==3)

                    q.add((x-1)*10+y);

             }

             if(y!=0){

                 if(grid[x][y-1]==2)

                    return true;

                 if(grid[x][y-1]==3)

                    q.add(x*10+(y-1));

             }

             if(x!=n-1){

                 if(grid[x+1][y]==2)

                    return true;

                 if(grid[x+1][y]==3)

                    q.add((x+1)*10+y);

             }

             if(y!=n-1){

                 if(grid[x][y+1]==2)

                    return true;

                 if(grid[x][y+1]==3)

                    q.add(x*10+(y+1));

             }

         }   

        return false;

    }
}