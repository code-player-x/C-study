//692https://leetcode-cn.com/problems/top-k-frequent-words/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //˼·
        //1������һ��mapͳ�Ƴ������ʳ��ֵĴ���
        //2������һ��multmap��1��mapͳ�Ƴ��Ĵ���intΪ����stringΪֵ������������ 
        //��Ϊmap���ǰ���string����ġ���������������ʳ��ֵĴ�����ͬ��string����ĸ˳��С���Ȳ�������ǰ�棬  
        //3����multimap��ǰK��ֵ��string����vector��
        map<string, int> countmap;
        for (auto e : words)
        {
            countmap[e]++;
        }

        multimap<int, string, greater<int>> countsort;//multimapĬ�������򣬵øĳɽ���
        for (auto e : countmap)
        {
            countsort.insert(make_pair(e.second, e.first));
        }

        vector <string> v;
        for (auto e : countsort)
        {
            v.push_back(e.second);
            if (--k == 0)
                break;

        }

        return v;
    }
};