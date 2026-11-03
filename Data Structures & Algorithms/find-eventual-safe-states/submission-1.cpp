class Solution {
private:
    bool dfs(int i,vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& path,vector<bool>& safe){
        visited[i]=true;
        path[i]=true;
        for(auto nbhr:graph[i]){
            if(!visited[nbhr]){
                if(!dfs(nbhr,graph,visited,path,safe)){
                    path[i]=false;
                    return false;
                }
            }else if(path[nbhr]){
                path[i]=false;
                return false;
            }else if(!safe[nbhr]){
                path[i]=false;
                return false;
            }
        }
        path[i]=false;
        safe[i]=true;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n,false);
        vector<bool>path(n,false);
        vector<bool>safe(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,visited,path,safe);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};