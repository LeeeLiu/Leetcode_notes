
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // 链表是空/ 链表只有一个元素 情况
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow就是链表的中间结点。
        // 如果中间结点有两个，slow就是第二个中间结点。
        return slow;
    }
};