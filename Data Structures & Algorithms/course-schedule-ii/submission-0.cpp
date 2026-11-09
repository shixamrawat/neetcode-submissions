class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<bool>visted(n,false);
        vector<int>indegree(n,0);
        vector<int>ans;

        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto nbhr:adj[curr]){
                indegree[nbhr]--;
                if(indegree[nbhr]==0)q.push(nbhr);
            }
        }
        if(ans.size()==n)return ans;
        return {};
    }
};
