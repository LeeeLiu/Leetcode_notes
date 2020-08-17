
// 110. 平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树。

// 高度平衡二叉树定义为：
// 一个二叉树 每个节点 的左右两个子树的 高度差 的 绝对值 不超过 1


class Solution {
public:
    int maxDepth(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root){
        if( root==NULL )
            return true;
        else if( abs(maxDepth(root->left) - maxDepth(root->right)) <= 1  &&
                 isBalanced(root->left) && isBalanced(root->right))
            return true;
        else
            return false;
    }
};