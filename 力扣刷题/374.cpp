//374https://leetcode-cn.com/problems/guess-number-higher-or-lower/
class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            long mid = l + (r - l) / 2;
            if (guess(mid) <= 0)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};