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
            if (isBadVersion(mid) && !isBadVersion(mid - 1))//midΪ����mid-1Ϊ�ã��ҵ��ˣ���һ�汾��Ϊmid
                break;
            else if (!isBadVersion(mid) && isBadVersion(mid + 1))//midΪ�ã�mid+1Ϊ�����ҵ��ˣ���һ�汾��Ϊmid+1
            {
                mid = mid + 1;
                break;
            }
            else if (isBadVersion(mid))//�����������������midΪ���������ұ߽�Ϊmid��1��
                right = mid - 1;
            //�����������������midΪ�ã�������߽�Ϊmid+1��
            else if (!isBadVersion(mid))
                left = mid + 1;
        }
        return mid;
    }
};