//815https://leetcode-cn.com/problems/bus-routes/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;
        queue<int>myque;//广度优先搜索辅助队列
        myque.push(source);
        unordered_map<int, vector<int>>hashMap;//hashMap[station]记录所有线路中存在station这个站点的线路下标
        int minsteps = 1, routesSize = routes.size();//minSteps为最少需要乘坐的公交车数量
        vector<bool>visitedRoute(routesSize, false);//标记已经访问过的线路
        //构建哈希表，统计每个站点出现的线路
        for (int i = 0; i < routesSize; ++i)
        {
            for (const auto& station : routes[i])
                hashMap[station].push_back(i);
        }
        while (!myque.empty()) {
            //将当前队列中所有的站点都向下寻找一条线路
            for (int i = myque.size(); i > 0; --i)
            {
                int frontstation = myque.front();
                myque.pop();
                //遍历frontstation这个站点所能到达的所有线路
                for (const auto& routeindex : hashMap[frontstation]) {
                    if (!visitedRoute[routeindex]) {//这条线路必须是未访问过的
                        visitedRoute[routeindex] = true;
                        //遍历routeindex这条线路中的所有站点
                        for (const auto& station : routes[routeindex]) {
                            if (station == target)//到达目的地
                                return minsteps;
                            myque.push(station);
                        }
                    }

                }
            }
            minsteps++;
        }
        return -1;
    }
};