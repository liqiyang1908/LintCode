class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>>pq;
        int primes[3] = { 2,3,5 };
        unordered_set<int>visited;
        pq.push(1);
        visited.insert(1);
        long number = 0;
        for (int i = 0; i < n; i++)
        {
            number = pq.top();
            pq.pop();
            for (auto prime : primes)
            {
                long temp = prime * number;
                if (visited.find(temp) == visited.end())
                {
                    visited.insert(temp);
                    pq.push(temp);
                }
            }
        }
        return number;
    }
};