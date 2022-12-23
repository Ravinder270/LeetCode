class Solution {
public:
     int m,n;
    
    void flood(vector<vector<bool>> &isSurrounded, vector<vector<char>> &board, vector<vector<bool>> &visited,int i, int j){

        if(board[i][j]=='X' || visited[i][j]) return; 
		
		/*Since in the previous line, the function terminates for cells that contain 'X' or have already been visited,
		the rest of the function is only executed for cells that contain 'O' adjacent to other 'O' */

        isSurrounded[i][j] = false;
        
        visited[i][j] = true;
        
        flood(isSurrounded,board,visited,max(0,i-1),j);//top
        flood(isSurrounded,board,visited,min(m-1,i+1),j);//bottom
        flood(isSurrounded,board,visited,i,max(0,j-1));//left
        flood(isSurrounded,board,visited,i,min(n-1,j+1));//left
        
        
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        vector<vector<bool>> isSurrounded(m,vector<bool>(n,true));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        // flood fill false starting from Os along the borders
        
        // initiating flood fill on Os along first and last row
        for(int j=0;j<n;j++){
            flood(isSurrounded,board,visited,0,j);
            flood(isSurrounded,board,visited,m-1,j);
        }

        // initiating flood fill on Os along first and last columns
        for(int i=1;i<m-1;i++){
            flood(isSurrounded,board,visited,i,0);
            flood(isSurrounded,board,visited,i,n-1);
        }
        
        // replacing all Os that are surrounded
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && isSurrounded[i][j])
                    board[i][j] = 'X';
            }
        }

    }
};