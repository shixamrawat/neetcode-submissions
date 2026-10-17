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
    TreeNode* findRight(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* helper(TreeNode* root){
        if(!root->left) return root->right;
        if(!root->right) return root->left;

        TreeNode* right=root->right;
        TreeNode* leftRight=findRight(root->left);
        leftRight->right=right;
        return root->left;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)return root;
        if(root->val==key) return helper(root);

        TreeNode* parent=root;
        TreeNode* curr=root;
        while(curr && curr->val!=key){
            parent=curr;
            if(curr->val>key){
                curr=curr->left;
            }else{
                curr=curr->right;
            }
        }
        if(!curr)return root;

        if(parent->left==curr){
            parent->left=helper(curr);
        }
        else if(parent->right==curr){
            parent->right=helper(curr);
        }
        return root;
    }
};