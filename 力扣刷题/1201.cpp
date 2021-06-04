//1201https://leetcode-cn.com/problems/ugly-number-iii/
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long lcm_ab = lcm<long>(a, b);
        long lcm_ac = lcm<long>(a, c);
        long lcm_bc = lcm<long>(b, c);
        long lcm_abc = lcm<long>(lcm_ab, c);
        int lo = min({ a, b, c }), hi = min(static_cast<long>(lo) * n, 2000000000l);
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid / a + mid / b + mid / c - mid / lcm_ab -
                mid / lcm_ac - mid / lcm_bc + mid / lcm_abc < n) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
// c++，二分查找，C++17已经在<numeric>里定义了最大公约数std::gcd<T>和最小公倍数std::lcm<T>啦
// 小于等于某个整数的丑数个数很好计算，即n/a+n/b+n/c-n/ab的最小公倍数-n/ac的最小公倍数-n/bc的最小公倍数+n/三者的最小公倍数
// 只需要在解空间内二分找到一个整数ans，使得[1, ans]内恰好有n个丑数，ans即为第n个丑数