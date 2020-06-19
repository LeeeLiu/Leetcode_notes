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
        vector<ListNode*>res;
        queue<TreeNode*>Q;
        if(root!=NULL)
            Q.push(root);
        TreeNode* cur;
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        int i;
        while(!Q.empty())
        {
            int len = Q.size();     // 记录每一层的元素个数
            for(i=0; i<len; i++)    //错过2：必须单独用len保存队列size，for循环里面size会变化
            {
                cur = Q.front();
                Q.pop();
                if(cur->left!=NULL)
                    Q.push(cur->left);
                if(cur->right!=NULL)
                    Q.push(cur->right);
                
                p->next = new ListNode(cur->val);
                p = p->next;
            }
            res.push_back(head->next);
            p = head;   //错过1
        }
        return res;
        // Write your code here
    }
};