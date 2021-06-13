//278https://leetcode-cn.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1)
            return 1;
        int left = 1, right = n;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (isBadVersion(mid) && !isBadVersion(mid - 1))//mid为坏，mid-1为好，找到了，第一版本即为mid
                break;
            else if (!isBadVersion(mid) && isBadVersion(mid + 1))//mid为好，mid+1为坏，找到了，第一版本即为mid+1
            {
                mid = mid + 1;
                break;
            }
            else if (isBadVersion(mid))//不满足上述情况，且mid为坏，更新右边界为mid—1；
                right = mid - 1;
            //不满足上述情况，且mid为好，更新左边界为mid+1；
            else if (!isBadVersion(mid))
                left = mid + 1;
        }
        return mid;
    }
};