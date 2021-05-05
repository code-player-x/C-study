//https://leetcode-cn.com/problems/delete-and-earn/

class Solution {
private:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> sum = { nums[0] };
        for (int i = 1; i < n; ++i) {
            int val = nums[i];
            if (val == nums[i - 1]) {
                sum.back() += val;
            }
            else if (val == nums[i - 1] + 1) {
                sum.push_back(val);
            }
            else {
                ans += rob(sum);
                sum = { val };
            }
        }
        ans += rob(sum);
        return ans;
    }
};

