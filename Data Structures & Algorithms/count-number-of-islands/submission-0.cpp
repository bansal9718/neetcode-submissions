class Solution {
public:
  void fn(int r , int c , vector<vector<bool>>&vis,vector<vector<char>>& grid,int islands) { 

      int n  = grid.size();
        int m = grid[0].size();
     vis[r][c] = true;

     int delrow[] = {-1,1,0,0};
     int delcol [] = {0,0,-1,1};
     
     for(int i=0;i<4;i++) { 
        int nrow = delrow[i] + r;
        int ncol = delcol[i] + c;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<=m && !vis[nrow][ncol] && grid[nrow][ncol]=='1') { 
         fn(nrow,ncol,vis,grid,islands);
        }
     }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int islands= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) { 

                if(!vis[i][j] && grid[i][j]=='1') { 
                    
                   fn(i,j,vis,grid,0);
                   islands++;
                   
                }
               
            }
        }
        return islands;





    }
};
