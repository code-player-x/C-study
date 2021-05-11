//1734
//https://leetcode-cn.com/problems/decode-xored-permutation/submissions/




class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int a = 0; int n = encoded.size();
        for (int i = 0; i < n; i += 2)
        {
            a ^= encoded[i];
        }
        int b = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            b ^= i;
        }
        vector<int>res(n + 1, 0);
        res[n] = a ^ b;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] = res[i + 1] ^ encoded[i];
        }
        return res;
    }
};