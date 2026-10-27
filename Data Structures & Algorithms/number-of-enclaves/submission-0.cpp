class Solution {
private:
    int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if((i==0||i==row-1||j==0||j==col-1)){
                    if(visited[i][j]==false && grid[i][j]==1){
                        q.push({i,j});
                        visited[i][j]=true;
                    }
                }
            }
        }

        while(!q.empty()){
            int f=q.front().first;
            int s=q.front().second;
            q.pop();
            visited[f][s]=true;

            for(int k=0;k<4;k++){
                int nf=f+direction[k][0];
                int ns=s+direction[k][1];
                if(nf>=0 && nf<row && ns>=0 && ns<col){
                    if(grid[nf][ns]==1 && !visited[nf][ns]){
                        visited[nf][ns]=true;
                        q.push({nf,ns});
                    }
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }

        return count;
        
    }
};