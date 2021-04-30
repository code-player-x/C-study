//137. 只出现一次的数字 II
//https://leetcode-cn.com/problems/single-number-ii/
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //1.开一个32位的数组用于存放数组中元素二进制中1的个数
        //2.统计数组中1的个数为3n-1的位置也就是模3结果为1的位置
        int bitArray[32] = { 0 };
        for (auto e : nums)
        {
            for (int i = 0; i < 32; ++i)
            {
                if (e & (1 << i))
                {
                    ++bitArray[i];
                }
            }
        }

        long long val = 0;
        for (int i = 0; i < 32; ++i)
        {
            if ((bitArray[i] % 3) == 1)
            {
                val = val + pow(2, i);
            }
        }
        return val;
    }
};