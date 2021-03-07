class DataStream {
public:
    unordered_set<int>removed;
    unordered_map<int, ListNode*>keytopre;
    ListNode* head, * tail;
    DataStream() {
        head = new ListNode(0);
        tail = head;
    }

    /**
     * @param num: next number in stream
     * @return: nothing
     */
    void remove(int num)
    {
        auto pre = keytopre[num];
        auto cur = pre->next;
        pre->next = cur->next;
        if (pre->next)
            keytopre[pre->next->val] = pre;
        else
            tail = pre;
        keytopre.erase(num);
        removed.insert(num);
    }
    void add(int num) {
        if (removed.find(num) != removed.end())
            return;
        if (keytopre.find(num) != keytopre.end())
        {
            remove(num);
            return;
        }

        auto new_node = new ListNode(num);
        keytopre[num] = tail;
        tail->next = new_node;
        tail = new_node;
    }

    /**
     * @return: the first unique number in stream
     */
    int firstUnique() {
        if (head->next == nullptr)
            return -1;
        return head->next->val;
    }
};