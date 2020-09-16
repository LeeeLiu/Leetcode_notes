

## 二叉树遍历

### 一、DFS：前、中、后遍历
1. 出处：lintcode
    - 66. 二叉树的前序遍历
    - 67. 二叉树的中序遍历
    - 68. Binary Tree Postorder Traversal
2. 定义
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
3. 实现
    - 版本1：递归
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

    - 版本2：迭代（非递归）
        + 借助堆栈。
            - 递归的方式，程序里的处理，本质上也是系统堆栈。
            - 这里用堆栈数据结构，模拟了这个过程。这种方法更快。
        + 思想：
            - 1先遍历左子树（往左边走，走到底）。
                * 因为：不论前/中/后序遍历（中左右，左中右，左右中），递归栈都是先左后右。
            - 2再回退，遍历右子树一次。
            - 3重复 步骤1、2。
        + 前序、中序 如下。（后序，目前还不会写）
            ```
            vector<int> res;
            stack<TreeNode *>  s ;
            vector<int> preorderTraversal(TreeNode * root) {
                while(root!=NULL || s.size()!=0)
                {
                    while(root!=NULL)   //一直往左边走，走到底
                    {
                        // 第一次访问
                        // 放在这里是 前序
                        res.push_back(root->val);  
                    
                        s.push(root);   //压入堆栈s。便于 第二次访问
                        root = root->left;  //遍历左子树
                    }
                    
                    if(s.size()!=0) //回退一次
                    {
                        root = s.top();     //第二次访问
                        s.pop();
                        
                        //放在这里是 中序
                        //res.push_back(root->val);

                        root = root->right; //遍历右子树
                    }
                }
                
                return res;
                // write your code here
            }
            ```        


### 二、BFS: 层序遍历
1. 实现
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

2. 相关题目
    - 遍历结果转化为数组/链表。例题2道如下。
        - [出处](https://www.lintcode.com/problem/binary-tree-level-order-traversal/leaderboard)
        - [242.将二叉树按照层级转化为链表](./convert-binary-tree-to-linked-lists-by-depth.cpp)
    
    - [637.二叉树的层平均值](./637.average-of-levels-in-binary-tree.cpp)