class Solution {
public:
    /**
     * @param head: a ListNode
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0), *p = dummy;
        while (head)
        {
            if (head->val != val)
            {
                p->next = head;
                p = p->next;
            }
            head = head->next;
        }
        p->next = nullptr;
        return dummy->next;
    }
};