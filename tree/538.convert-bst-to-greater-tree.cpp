
/*
538. 把二叉搜索树转换为累加树
    给定一个二叉搜索树（BST，Binary Search Tree），
    把它转换成为累加树（Greater Tree)，
    使得每个节点的值，是原来的节点值 加上 所有大于它的节点值之和。
*/

// 回顾：
    // 对于BST，中序遍历结果本来就是从小到大顺序的。
// 思路：
    // 反向中序遍历。

class Solution {
public:
    int sum = 0;
    void dfs(TreeNode* root){
        if(root){
            dfs(root->right);
            root->val += sum;
            sum = root->val;
            dfs(root->left);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};