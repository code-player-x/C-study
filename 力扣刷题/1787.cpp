//1787https://leetcode-cn.com/problems/make-the-xor-of-all-segments-equal-to-zero/

class Solution {
private:
    // x �ķ�ΧΪ [0, 2^10)
    static constexpr int MAXX = 1 << 10;
    // ����ֵ��Ϊ�˷�ֹ�������ѡ�� INT_MAX / 2
    static constexpr int INFTY = INT_MAX / 2;

public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(MAXX, INFTY);
        // �߽����� f(-1,0)=0
        f[0] = 0;

        for (int i = 0; i < k; ++i) {
            // �� i ����Ĺ�ϣӳ��
            unordered_map<int, int> cnt;
            int size = 0;
            for (int j = i; j < n; j += k) {
                ++cnt[nums[j]];
                ++size;
            }

            // ��� t2
            int t2min = *min_element(f.begin(), f.end());

            vector<int> g(MAXX, t2min);
            for (int mask = 0; mask < MAXX; ++mask) {
                // t1 ����Ҫö�� x �������
                for (auto [x, countx] : cnt) {
                    g[mask] = min(g[mask], f[mask ^ x] - countx);
                }
            }

            // �����˼��� size
            for_each(g.begin(), g.end(), [&](int& val) {val += size; });
            f = move(g);
        }

        return f[0];
    }
};