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
			sum += nums[i];//����ǰ׺��
			int tmod = sum%k;//����ǰ׺��%k����
			if (tmod == 0 && i>1) return true;//�������Ϊ0������i>1  ����true
			if (mymap.find(tmod) != mymap.end()){//��������ڹ�ϣ�г��ֹ�������i-mymap[tmod]>1���򷵻�true
				if (i - mymap[tmod] > 1) return true;
			}
			else mymap[tmod] = i;//�����������Ϊkey����Ӧ��i��Ϊvalue
		}
		return false;
	}
};