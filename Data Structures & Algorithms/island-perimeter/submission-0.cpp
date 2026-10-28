class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
        int row=grid.size();
        int col=grid[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int ni=i+direction[k][0];
                        int nj=j+direction[k][1];
                        if(ni<0 || ni>=row || nj<0 || nj>=col){
                            count++;
                        }else{
                            if(grid[ni][nj]==0)count++;
                        }
                    }
                }

                
            }
        }
        return count;
    }
};