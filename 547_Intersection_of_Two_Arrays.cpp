class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        if (nums1.size() < 1 || nums2.size() < 1)
            return res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                if (res.empty() || *(res.end()-1) != nums1[i])
                    res.push_back(nums1[i]);
                i++;
                j++;
            }
            else
                nums1[i] < nums2[j] ? i++ : j++;
        }
        return res;
    }
};