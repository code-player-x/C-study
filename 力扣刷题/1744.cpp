//1744https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
class Solution {
public:
    using LL = long long;
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<LL>sum(n);
        sum[0] = candiesCount[0];
        for (int i = 1; i < n; ++i)
        {
            sum[i] = sum[i - 1] + candiesCount[i];
        }
        vector<bool> ans;
        for (auto& q : queries)
        {
            int ftype = q[0], fday = q[1], fcap = q[2];

            LL x1 = fday + 1;
            LL y1 = (LL)(fday + 1) * fcap;
            LL x2 = (ftype == 0 ? 1 : sum[ftype - 1] + 1);
            LL y2 = sum[ftype];

            ans.push_back(!(x1 > y2 || y1 < x2));
        }
        return ans;
    }
};