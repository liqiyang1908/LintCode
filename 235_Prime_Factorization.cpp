class Solution {
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    vector<int> primeFactorization(int num) {
        vector<int>res;
        int i;
        for (i = 2; i * i <= num; i++)
        {
            while (num % i == 0)
            {
                num = num / i;
                res.push_back(i);
            }
        }
        if (num > 1)
            res.push_back(num);
        return res;
    }
};