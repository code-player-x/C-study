//852https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, ans = 0;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (arr[mid] > arr[mid + 1])
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return l;
    }
};