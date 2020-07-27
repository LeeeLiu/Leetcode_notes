/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root) {
        if(root==NULL)
           return 0;
        int left_depth = dfs(root->left);        
        int right_depth =  dfs(root->right);
        return max(left_depth, right_depth) +1;
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};