//137. ֻ����һ�ε����� II
//https://leetcode-cn.com/problems/single-number-ii/
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //1.��һ��32λ���������ڴ��������Ԫ�ض�������1�ĸ���
        //2.ͳ��������1�ĸ���Ϊ3n-1��λ��Ҳ����ģ3���Ϊ1��λ��
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