class KeyValue {
public:
    int key, value;
    KeyValue* next;
    KeyValue(int key, int value) {
        next = nullptr;
        this->key = key;
        this->value = value;
    }
    KeyValue() {
        this->next = NULL;
        this->key = 0;
        this->value = 0;
    }
};

class LRUCache {
public:
    unordered_map<int, KeyValue*>keytopre;
    KeyValue* head, * tail;
    int capacity, size;

    /*
    * @param capacity: An integer
    */LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->head = new KeyValue(0, 0);
        this->tail = head;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    void movetotail(int key)
    {
        auto pre = keytopre[key];
        auto cur = pre->next;
        if (tail == cur)
            return;
        pre->next = pre->next->next;
        tail->next = cur;

        if (pre->next)
            keytopre[pre->next->key] = pre;
        keytopre[cur->key] = tail;
        tail = cur;
        tail->next = nullptr;
    }
    int get(int key) {
        if (keytopre.find(key) == keytopre.end())
            return -1;
        movetotail(key);
        return tail->value;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (get(key) != -1)
        {
            auto pre = keytopre[key];
            pre->next->value = value;
            return;
        }
        if (size < capacity)
        {
            size++;
            auto cur = new KeyValue(key, value);
            tail->next = cur;
            keytopre[cur->key] = tail;
            tail = cur;
            return;
        }
        auto first = head->next;
        keytopre.erase(first->key);
        first->key = key;
        first->value = value;
        keytopre[first->key] = head;
        movetotail(key);
    }
};