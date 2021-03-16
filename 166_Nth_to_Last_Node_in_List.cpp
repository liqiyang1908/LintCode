
class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: Nth to last node of a singly linked list.
     */
    ListNode* nthToLast(ListNode* head, int n) {
        ListNode* tail = head;
        for (int i = 0; i < n; i++)
            tail = tail->next;
        while (tail)
        {
            head = head->next;
            tail = tail->next;
        }
        return head;
    }
};