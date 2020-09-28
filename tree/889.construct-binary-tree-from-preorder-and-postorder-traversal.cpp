

// 889. 根据前序和后序遍历构造二叉树
    // 注意，答案 不唯一


// 前置知识
    // 先序遍历 pre  是 【根节点 —> 左子树 —> 右子树】，下标是[left_1, right_1]
    // 后序遍历 post 是 【左子树 —> 右子树 —> 根节点】，下标是[left_2, right_2]

    // 后序的根节点在最后，先序的根节点在最前。
        // 即，pre[left_1] 和 post[right_2] 一样
        // 因此，可以 递归地 划分左右子树。


// 思路
    // 记录 后序 遍历序列里 每个元素 下标。(如果 以 前序 为参照)
        // 在 前序 遍历序列里，找到 下一个 左子树 根节点（下标就是 left_1 +1），值为 val
        // 在 后序 遍历序列里，找到 val 对应的 下标 i
        // 计算 左子树 节点个数 subTree_size，
        // 确定 递归 边界，从而 递归地 划分左右子树
            // 先 left，再 right
        

class Solution {
public:
    TreeNode* dfs(vector<int>& pre, vector<int>& post,  
                                int left_1, int right_1,    // pre 下标
                                int left_2, int right_2,    // post 下标
                                unordered_map<int, int>& post_idx_map) {
        if(left_1 > right_1)
            return nullptr;
        
        // pre[left_1] 和 post[right_2] 一样的
        TreeNode* root = new TreeNode(pre[left_1]);

        if(left_1 == right_1)
            return root;

        // 找分割点
        // 在 前序遍历序列里，找到 下一个 左子树 根节点（下标就是 left_1 +1）
        // 在 后序 里，找到 对应的 下标 i
        // 计算 左子树 节点个数 subTree_size，
        // 确定 递归 边界，从而 递归地 划分左右子树
        
        int i = post_idx_map[ pre[left_1 +1] ];
        int subTree_size = i - left_2 +1;
        
        // 先 left，再 right
        root->left  = dfs(pre,post,
                                    left_1+1,  left_1+subTree_size,
                                    left_2,    left_2+subTree_size-1,        
                                    post_idx_map);
        root->right = dfs(pre,post,
                                    left_1+subTree_size+1,  right_1, 
                                    left_2+subTree_size,    right_2-1,
                                    post_idx_map);
        return root;
    }
    // 主函数
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = post.size();
        unordered_map<int, int>post_idx_map;
        for(int i=0; i<n; i++){
            post_idx_map[post[i]] = i;
        }
        return dfs(pre,post, 
                            0, n-1, 
                            0, n-1, 
                            post_idx_map);
    }
};