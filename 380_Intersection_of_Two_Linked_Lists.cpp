class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    int size(ListNode* head)
    {
        int size = 0;
        while (head)
        {
            head = head->next;
            size++;
        }
        return size;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int Asize = size(headA);
        int Bsize = size(headB);
        if (Asize < Bsize)
            swap(headA, headB);
        
        int diff = abs(Asize - Bsize);
        for (int i = 0; i < diff; i++)
        {
            headA = headA->next;
        }
        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};