class Solution {
private:
    // ����ֵ
    // ѡ�� INT_MAX / 2 ��ԭ���Ƿ�ֹ����������
    static constexpr int INFTY = INT_MAX / 2;

public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // ����ɫ����Ϊ�� 0 ��ʼ��ţ�û�б�Ϳɫ���Ϊ -1
        for (int& c : houses) {
            --c;
        }

        // dp ����Ԫ�س�ʼ��Ϊ����ֵ
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, INFTY)));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (houses[i] != -1 && houses[i] != j) {
                    continue;
                }

                for (int k = 0; k < target; ++k) {
                    for (int j0 = 0; j0 < n; ++j0) {
                        if (j == j0) {
                            if (i == 0) {
                                if (k == 0) {
                                    dp[i][j][k] = 0;
                                }
                            }
                            else {
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                            }
                        }
                        else if (i > 0 && k > 0) {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j0][k - 1]);
                        }
                    }

                    if (dp[i][j][k] != INFTY && houses[i] == -1) {
                        dp[i][j][k] += cost[i][j];
                    }
                }
            }
        }

        int ans = INFTY;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[m - 1][j][target - 1]);
        }
        return ans == INFTY ? -1 : ans;
    }
};

//���ӣ�https ://leetcode-cn.com/problems/paint-house-iii/solution/fen-shua-fang-zi-iii-by-leetcode-solutio-powb/
