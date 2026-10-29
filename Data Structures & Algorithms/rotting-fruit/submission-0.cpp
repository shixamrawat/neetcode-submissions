class Solution {
private:
    vector<vector<int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>q;
        
        int ans=0;
        int fresh=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1) fresh++;
            }
        }
        while(!q.empty()){
            ans++;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto curr=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int nr=curr.first+direction[j][0];
                    int nc=curr.second+direction[j][1];
                    if(nr>=0 && nc>=0 && nr<row && nc<col){
                        if(grid[nr][nc]==1){
                            q.push({nr,nc});
                            fresh--;
                            grid[nr][nc]=2;
                        }
                    }
                }
            }
        }
        if(fresh>0)return -1;
        return ans==0?0:ans-1;
    }
};