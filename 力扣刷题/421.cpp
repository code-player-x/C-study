//421https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/

class Solution {
private:
    // ���λ�Ķ�����λ���Ϊ 30
    static constexpr int HIGH_BIT = 30;
    
public:
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; --k) {
            unordered_set<int> seen;
            // �����е� pre^k(a_j) �����ϣ����
            for (int num : nums) {
                // ���ֻ�뱣�������λ��ʼ���� k ��������λΪֹ�Ĳ���
                // ֻ�轫������ k λ
                seen.insert(num >> k);
            }

            // Ŀǰ x ���������λ��ʼ���� k+1 ��������λΪֹ�Ĳ���
            // ���ǽ� x �ĵ� k ��������λ��Ϊ 1����Ϊ x = x*2+1
            int x_next = x * 2 + 1;
            bool found = false;

            // ö�� i
            for (int num : nums) {
                if (seen.count(x_next ^ (num >> k))) {
                    found = true;
                    break;
                }
            }

            if (found) {
                x = x_next;
            }
            else {
                // ���û���ҵ������ʽ�� a_i �� a_j����ô x �ĵ� k ��������λֻ��Ϊ 0
                // ��Ϊ x = x*2
                x = x_next - 1;
            }
        }
        return x;
    }
};

