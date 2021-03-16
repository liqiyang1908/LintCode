class Solution {
public:
    /**
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p;
        while (head)
        {
            p = head->next;
            while (p && head->val == p->val)
                p = p->next;
            head->next = p;
            head = head->next;
        }
        return dummy->next;
    }
};