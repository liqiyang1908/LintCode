class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0), *fast = head, *p = dummy;
        dummy->next = head;
        while (n-- > 0)
            fast = fast->next;
        while (fast)
        {
            p = p->next;
            fast = fast->next;
        }
        p->next = p->next->next;
        return dummy->next;
    }
};