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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        queue<TreeNode*>Q;
        Q.push(root);
        TreeNode* cur;
        vector<ListNode*> res;
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        while(!Q.empty())
        {
            // 记录每一层的元素个数。
            int len = Q.size();
            for(int i=0; i<len; i++)
            {
                cur = Q.front();
                Q.pop();
                if(cur==NULL)
                    continue;
                
                Q.push(cur->left);
                Q.push(cur->right);
                
                p->next = new ListNode(cur->val);
                p = p->next;
            }
            
            res.push_back(head->next);
            p = head;
        }
        // 到最后一层的时候，由于叶子节点的左右节点都是NULL，所以res里面会把最后一层的数据重复加进去。这里删去。
        res.pop_back(); 
        return res;
        // Write your code here
    }
};