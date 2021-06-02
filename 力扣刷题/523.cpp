//523https://leetcode-cn.com/problems/continuous-subarray-sum/
class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		if (n<2) return false;
		unordered_map<int, int> mymap;
		mymap[0] = -1;
		int sum = 0;
		for (int i = 0; i<n; i++){
			sum += nums[i];//计算前缀和
			int tmod = sum%k;//计算前缀和%k余数
			if (tmod == 0 && i>1) return true;//如果余数为0，并且i>1  返回true
			if (mymap.find(tmod) != mymap.end()){//如果余数在哈希中出现过，并且i-mymap[tmod]>1，则返回true
				if (i - mymap[tmod] > 1) return true;
			}
			else mymap[tmod] = i;//否则把余数设为key，对应的i设为value
		}
		return false;
	}
};