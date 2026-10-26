class Solution {
public:
    void bfs(int i,vector<vector<int>>& adj , vector<bool>& visited){
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int curr=q.front();
            visited[curr]=true;
            q.pop();
            for(auto& nbhr:adj[curr]){
                if(!visited[nbhr]){
                    visited[nbhr]=true;
                    q.push(nbhr);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool>visited(n+1,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                ans++;
                bfs(i,adj,visited);
            }
        }
        return ans;
    }
};