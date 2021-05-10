//https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		if (m > bloomDay.size() / k) {
			return -1;
		}
		int low = INT_MAX, high = 0;
		int length = bloomDay.size();
		for (int i = 0; i < length; i++) {
			low = min(low, bloomDay[i]);//������������С����
			high = max(high, bloomDay[i]);//�����������������
		}
		while (low < high) {
			int days = (high - low) / 2 + low;//����ȡ��
			if (canMake(bloomDay, days, m, k)) {
				high = days;//��ȡ���м�������������Ԥ�������������highΪ�м�����
			}
			else {//��ȡ���м�������������Ԥ�������������lowΪ�м�����+1��
				low = days + 1;
			}
		}
		return low;//��high��low����ʱ��low��ֵ��������Ԥ����������С����
	}

	bool canMake(vector<int>& bloomDay, int days, int m, int k) {
		int bouquets = 0;//��������Ŀ
		int flowers = 0;//һ�������л������Ŀ
		int length = bloomDay.size();
		for (int i = 0; i < length && bouquets < m; i++) {
			if (bloomDay[i] <= days) {//����ǰbloomDay[i]С�ڵ���ȡ�е�����days�����ʾ��ǰ���������days����Ϊһ������һ��
				flowers++;
				if (flowers == k) {//������������kʱ����ʾһ�����Ѿ�����
					bouquets++;//���������+1
					flowers = 0;//��������Ϊ0����ʼ�µ�һ����
				}
			}
			else {//����ǰbloomDay[i]����ȡ�е�����days�����ʾ��ǰ���䲻����days����Ϊһ������һ�䣬������ȡ��Ҫ�󣬻�����������Ϊ0
				flowers = 0;
			}
		}
		return bouquets >= m;
	}
};
