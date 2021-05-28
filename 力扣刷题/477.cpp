//477.汉明距离总和https://leetcode-cn.com/problems/total-hamming-distance/
#include<vector>
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int c, ans = 0, n = nums.size();
        for (int i = 0; i < 30; ++i)
        {
            c = 0;
            for (int val : nums)//计算数组所有数字中第i位为1的数字的个数
            {
                c += (val >> i) & 1;
            }
            ans += c * (n - c);
        }
        return ans;
    }
};