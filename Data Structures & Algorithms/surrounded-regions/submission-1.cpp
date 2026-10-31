class Solution {
private:
    vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};

public:
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<char>>temp(row,vector<char>(col,'X'));
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                temp[i][0]='O';
            }
            if(board[i][col-1]=='O'){
                q.push({i,col-1});
                temp[i][col-1]='O';
            }
        }
        for(int j=0;j<col;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                temp[0][j]='O';
            }
            if(board[row-1][j]=='O'){
                q.push({row-1,j});
                temp[row-1][j]='O';
            }
        }
        
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(int j=0;j<4;j++){
                int nr=curr.first+direction[j][0];
                int nc=curr.second+direction[j][1];

                if(nr>0 && nc>0 && nr<row-1 && nc<col-1 && board[nr][nc]=='O' && temp[nr][nc] == 'X'){
                    temp[nr][nc]='O';
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                board[i][j]=temp[i][j];
            }
        }
    }
};