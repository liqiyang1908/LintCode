class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    queue<int>q1;
    queue<int>q2;
    void push(int x) {
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
    }

    /*
     * @return: nothing
     */
    void pop() {
        q2.pop();
    }

    /*
     * @return: An integer
     */
    int top() {
        return q2.front();
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        return q2.empty();
    }
};