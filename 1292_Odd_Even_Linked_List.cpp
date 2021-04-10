class Solution {
public:
    /**
     * @param head: a singly linked list
     * @return: Modified linked list
     */
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* oddhead = new ListNode(0), * evenhead = new ListNode(0);
        ListNode* l1 = oddhead, * l2 = evenhead;
        while (head && head->next)
        {
            l1->next = head;
            l2->next = head->next;
            l1 = l1->next;
            l2 = l2->next;
            head = head->next->next;
        }
        if (head)
        {
            l1->next = head;
            l1 = l1->next;
        }
        l1->next = evenhead->next;
        l2->next = nullptr;
        return oddhead->next;
    }
};