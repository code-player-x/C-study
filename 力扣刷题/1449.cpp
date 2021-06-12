//1449https://leetcode-cn.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int c : cost) {
            for (int j = c; j <= target; ++j) {
                dp[j] = max(dp[j], dp[j - c] + 1);
            }
        }
        if (dp[target] < 0) {
            return "0";
        }
        string ans;
        for (int i = 8, j = target; i >= 0; i--) {
            for (int c = cost[i]; j >= c && dp[j] == dp[j - c] + 1; j -= c) {
                ans += '1' + i;
            }
        }
        return ans;
    }
};

