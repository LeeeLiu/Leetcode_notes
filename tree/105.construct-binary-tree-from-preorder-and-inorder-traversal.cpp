
// 105. 从前序与中序遍历序列构造二叉树


class Solution {
public:
    int pre_start_idx=0;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,  
                            int left, int right, 
                            unordered_map<int, int>& inorder_idx_map) {                
        if(left>right)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_start_idx]);
        int i = inorder_idx_map[root->val];
        // 前序遍历-首元素，就是 子树 的根
        pre_start_idx ++;
        // 先 left，再 right
        root->left  = dfs(preorder,inorder, left, i-1,  inorder_idx_map);
        root->right = dfs(preorder,inorder, i+1, right, inorder_idx_map);
        return root;
    }
    // 主函数
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int>inorder_idx_map;
        for(int i=0; i<n; i++){
            inorder_idx_map[inorder[i]] = i;
        }
        return dfs(preorder,inorder, 0,n-1, inorder_idx_map);
    }
};