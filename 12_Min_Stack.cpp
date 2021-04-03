class MinStack {
public:
    stack<int>minstk;
    stack<int>stk;
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        stk.push(number);
        if (minstk.empty() || minstk.top() >= number)
            minstk.push(number);
    }

    /*
     * @return: An integer
     */
    int pop() {
        int val = stk.top();
        if (val == minstk.top())
            minstk.pop();
        stk.pop();
        return val;
    }

    /*
     * @return: An integer
     */
    int min() {
        return minstk.top();
    }
};