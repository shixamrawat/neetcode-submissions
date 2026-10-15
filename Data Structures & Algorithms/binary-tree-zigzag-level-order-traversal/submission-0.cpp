/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*>q;

        q.push(root);
        bool order=true;

        while(!q.empty()){
            int n=q.size();
            vector<int>curr(n);
            for(int i=0;i<n;i++){
                int temp=q.front()->val;
                int idx=order?i:n-1-i;
                curr[idx]=temp;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(curr);
            order=!order;
        }  
        return ans;
    }
};