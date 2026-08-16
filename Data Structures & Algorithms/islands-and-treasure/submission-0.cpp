class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
      long long INF = 2147483647;
        queue<pair<pair<int, int>, int>> q; 

      vector<vector<int>>copy = grid;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }

int delrow [] = {-1,1,0,0};
int delcol[] = {0,0,-1,1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int level = q.front().second;

            q.pop();
           

            for(int i=0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==INF){
                   grid[nrow][ncol] = level+1;
                   q.push({{nrow, ncol}, level + 1});
                }
                
            }


        }


       
    }
};
