

// 106. 从中序与后序遍历序列构造二叉树

class Solution {
public:
    int post_end_idx;
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, 
                            int left, int right, 
                            unordered_map<int, int>& inorder_idx_map) {                
        if(left>right)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[post_end_idx]);
        int i = inorder_idx_map[root->val];
        // 后序遍历-末尾元素，就是 子树 的根
        post_end_idx --;
        // 先 right，再left
        root->right = dfs(inorder,postorder, i+1, right, inorder_idx_map);
        root->left  = dfs(inorder,postorder, left, i-1,  inorder_idx_map);
        return root;
    }
    // 主函数
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int>inorder_idx_map;
        for(int i=0; i<n; i++){
            inorder_idx_map[inorder[i]] = i;
        }
        post_end_idx = n-1;
        return dfs(inorder,postorder, 0,n-1, inorder_idx_map);
    }
};