class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param val: An integer.
     * @return: The head of new linked list.
     */
    ListNode* insertNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0), *p = new ListNode(val);
        dummy->next = head;
        ListNode* pre = dummy;
        while (head && head->val < val)
        {
            pre = pre->next;
            head = head->next;
        }
        if (head)
        {
            pre->next = p;
            p->next = head;
        }
        else
            pre->next = p;
        return dummy->next;
    }
};