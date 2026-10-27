class Solution {
private:
    int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int row=image.size();
        int col=image[0].size();

        if(image[sr][sc]==color)return image;
        
        queue<pair<int,int>>q;
        ans[sr][sc]=color;
        q.push({sr,sc});


        while(!q.empty()){
            int f=q.front().first;
            int s=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nf=f+direction[i][0];
                int ns=s+direction[i][1];
                if(nf>=0 && ns>=0 && nf<row && ns<col && ans[nf][ns]==image[sr][sc]){
                    q.push({nf,ns});
                    ans[nf][ns]=color;
                }
            }
        }
        return ans;
    }
};