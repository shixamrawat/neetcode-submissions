class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int>q;
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]!=-1)continue;
            color[i]=0;
            q.push(i);
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(auto& nbhr:graph[curr]){
                    if(color[nbhr]==-1){
                        color[nbhr]=!color[curr];
                        q.push(nbhr);
                    }else if(color[nbhr]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
