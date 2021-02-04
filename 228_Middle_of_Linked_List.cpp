class Solution {
public:

    ListNode* middleNode(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* slow = head, * fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};