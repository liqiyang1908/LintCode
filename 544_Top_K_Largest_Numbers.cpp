class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int>& nums, int k) {
        vector<int>res;
        priority_queue<int, vector<int>, greater<int>>pq;
        for (auto num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};