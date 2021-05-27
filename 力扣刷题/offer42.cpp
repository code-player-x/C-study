//剑指 Offer 42. 连续子数组的最大和https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int former = 0;
        int cur = nums[0];
        int max = nums[0];
        for (int num : nums)
        {
            cur = num;
            if (former > 0)cur = cur + former;
            if (cur > max) max = cur;
            former = cur;
        }
        return max;
    }
};