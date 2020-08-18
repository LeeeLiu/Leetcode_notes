    

## 两道题：关于BST(binary-search-tree,二叉搜索树)
1. 回顾：
    - BST性质是，每个节点的左孩子比它小，右孩子比它大。中序遍历序列是递增的。
    - 平衡BST是`每个节点的两棵子树高度差不超过1`的BST。
2. 思路
    - `1382.将二叉搜索树变平衡`思路是，先由BST得到中序遍历数组序列(是递增的)，再由序列建树；
    - 由中序遍历序列建树，就是`108.将有序数组转换为(平衡)二叉搜索树`要做的。
        + 根据二分法，先把整个数组中间位置mid的值(对于长度为偶数的数组，中间左边/右边均可)作为根节点，
        + 递归地建树：由[left,mid-1]建立左子树, 由[mid+1,right]建立右子树。

#### 1382.将二叉搜索树变平衡
1. [来源](https://leetcode-cn.com/problems/balance-a-binary-search-tree/)
2. 实现
    ```
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
        vector<int>in_order_seq;
        void in_order_track(TreeNode* root){
            if(root!=NULL){
                in_order_track(root->left);
                in_order_seq.push_back(root->val);
                in_order_track(root->right);
            }
        }
        
        TreeNode* AVL_from_in_order_seq(int left, int right){
            if(left <= right){
                int mid = (left+right)/2;
                TreeNode* res = new TreeNode(in_order_seq[mid]);
                res->left = AVL_from_in_order_seq(  left, mid-1);
                res->right = AVL_from_in_order_seq(  mid+1, right);
                return res;
            }
            else{
                return NULL;
            }        
        }

        TreeNode* balanceBST(TreeNode* root) {
            in_order_track(root);
            // AVL就是balanceBST
            return AVL_from_in_order_seq( 0, in_order_seq.size()-1);
        }
    };
    ```

#### 108.将有序数组转换为(平衡)二叉搜索树
1. [来源](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)
2. 实现（和1382题目的第二步骤一样）
    ```
    class Solution {
    public:
        TreeNode* AVL_from_in_order_seq(vector<int>& in_order_seq, int left, int right){                
            if(left <= right){
                int mid = (left+right)/2;
                TreeNode* res = new TreeNode(in_order_seq[mid]);
                res->left = AVL_from_in_order_seq(in_order_seq, left, mid-1);
                res->right = AVL_from_in_order_seq(in_order_seq, mid+1, right);
                return res;
            }
            else{
                return NULL;
            }       
        }

        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return AVL_from_in_order_seq(nums, 0, nums.size()-1);
        }
    };
    ```