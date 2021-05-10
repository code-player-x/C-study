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
			low = min(low, bloomDay[i]);//找制作花束最小天数
			high = max(high, bloomDay[i]);//找制作花束最多天数
		}
		while (low < high) {
			int days = (high - low) / 2 + low;//二分取中
			if (canMake(bloomDay, days, m, k)) {
				high = days;//若取的中间天数可以作出预订花束，则更新high为中间天数
			}
			else {//若取的中间天数不能作出预订花束，则更新low为中间天数+1；
				low = days + 1;
			}
		}
		return low;//当high和low相遇时，low的值就是作出预订花束的最小天数
	}

	bool canMake(vector<int>& bloomDay, int days, int m, int k) {
		int bouquets = 0;//花束的数目
		int flowers = 0;//一个花束中花朵的数目
		int length = bloomDay.size();
		for (int i = 0; i < length && bouquets < m; i++) {
			if (bloomDay[i] <= days) {//若当前bloomDay[i]小于等于取中的天数days，则表示当前花朵可以在days内作为一束花的一朵
				flowers++;
				if (flowers == k) {//当花朵数等于k时，表示一束花已经凑齐
					bouquets++;//凑齐后花束数+1
					flowers = 0;//花朵数置为0，开始新的一束花
				}
			}
			else {//若当前bloomDay[i]大于取中的天数days，则表示当前花朵不能在days内作为一束花的一朵，因相邻取花要求，花朵数重新置为0
				flowers = 0;
			}
		}
		return bouquets >= m;
	}
};
