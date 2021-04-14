#include<iostream>
using namespace std;
#include<vector>

class Solution {
    vector<int> tmp;
public:
    void merge(vector<int>& nums, int begin, int end)
    {
        if (begin >= end)
            return;
        int mid = (begin + end) >> 1;
        merge(nums, begin, mid);
        merge(nums, mid + 1, end);

        int i = begin, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= end)
        {
            if (nums[i] <= nums[j])
                tmp[cnt++] = nums[i++];
            if (nums[i] > nums[j])
                tmp[cnt++] = nums[j++];

        }
        while (i <= mid)
            tmp[cnt++] = nums[i++];
        while (j <= end)
            tmp[cnt++] = nums[j++];
        for (int i = 0; i < end - begin + 1; ++i)
        {
            nums[i + begin] = tmp[i];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize((int)nums.size(), 0);
        merge(nums, 0, (int)nums.size() - 1);
        return nums;

    }
};

//https://leetcode-cn.com/problems/sort-an-array/