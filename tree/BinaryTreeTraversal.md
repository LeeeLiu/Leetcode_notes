

## 二叉树遍历

### DFS：前、中、后遍历
   - 出处：lintcode
        66. 二叉树的前序遍历
        67. 二叉树的中序遍历
        68. Binary Tree Postorder Traversal

   - 定义
        ```
        /**
        * Definition of TreeNode:
        * class TreeNode {
        * public:
        *     int val;
        *     TreeNode *left, *right;
        *     TreeNode(int val) {
        *         this->val = val;
        *         this->left = this->right = NULL;
        *     }
        * }
        */
        ```

    1. 递归
    ```
    class Solution {
    public:
        vector<int> res;
        vector<int> orderTraversal(TreeNode * root)
        {
            if(root!=NULL)
            {
                res.push_back(root->val); 
                //放在这里是前序，放在//1后面是中序，放在//2后面是后序。
                orderTraversal(root->left);    //1
                orderTraversal(root->right);   //2                     
            }
            return res;
        }
    };
    ```

    2. 非递归：借助堆栈。递归的方式，程序里的处理，本质上也是系统堆栈。这里用堆栈数据结构，模拟了这个过程。这种方法更快。
        - 前序
        ```
        vector<int> res;
        stack<TreeNode *>  s ;
        vector<int> preorderTraversal(TreeNode * root) {
            while(root!=NULL || s.size()!=0)
            {
                while(root!=NULL)   //一直往左边走，走到底
                {
                    res.push_back(root->val);  //前序
                
                    s.push(root);   //压入堆栈s,   第一次访问
                    root = root->left;  //遍历左子树
                }
                
                if(s.size()!=0) //回退一次
                {
                    root = s.top();     //第二次访问
                    s.pop();
                    //res.push_back(root->val); //放在这里是中序
                    root = root->right; //遍历右子树
                }
            }
            
            return res;
            // write your code here
        }
        ```
        - 中
            参见上面的版本    
        - 后
            待补充。




### BFS: 层序遍历
- [出处](https://www.lintcode.com/problem/binary-tree-level-order-traversal/leaderboard)
```
vector<vector<int>> levelOrder(TreeNode * root) {
        queue<TreeNode*> Q;
        int i, CurLevelCount;
        vector<int>  CurLevel;
        vector<vector<int>> res;
        if(root==NULL)
            return res;
            
        Q.push(root);       // BFS
        while(!Q.empty())
        {
            CurLevelCount = Q.size();   //for循环为了组织每一层的节点
            for (i=0; i<CurLevelCount; i++)
            {
                root = Q.front();   //访问队列最头边的节点
                CurLevel.push_back(root->val);  //记录每一层里每个节点
                
                Q.pop();    //每出队一个节点，就把该节点的孩子入队。
                if(root->left!=NULL)  Q.push(root->left);
                if(root->right!=NULL) Q.push(root->right);
            }
            res.push_back(CurLevel);    //把一层的节点放进res
            CurLevel.clear();
        }
        return res;

    }
```
- [242.将二叉树按照层级转化为链表](./convert-binary-tree-to-linked-lists-by-depth.cpp)