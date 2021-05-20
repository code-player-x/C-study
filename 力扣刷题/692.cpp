//692https://leetcode-cn.com/problems/top-k-frequent-words/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //思路
        //1、先用一个map统计出各单词出现的次数
        //2、再用一个multmap以1中map统计出的次数int为键，string为值，按降序排序 
        //因为map中是按照string排序的。所以如果两个单词出现的次数相同，string中字母顺序小的先插入排在前面，  
        //3、把multimap的前K个值的string传入vector中
        map<string, int> countmap;
        for (auto e : words)
        {
            countmap[e]++;
        }

        multimap<int, string, greater<int>> countsort;//multimap默认是升序，得改成降序
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