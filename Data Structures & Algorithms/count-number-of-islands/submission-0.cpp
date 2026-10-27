class Solution {
private:
    int directions[4][2] = {{1, 0}, {-1, 0},
                            {0, 1}, {0, -1}};

public:

    void bfs(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='0';
        queue<pair<int,int>>q;
        q.push({i,j});
        
        while(!q.empty()){
            int f=q.front().first;
            int s=q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = f + directions[k][0];
                int nc = s + directions[k][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};