//815https://leetcode-cn.com/problems/bus-routes/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;
        queue<int>myque;//�������������������
        myque.push(source);
        unordered_map<int, vector<int>>hashMap;//hashMap[station]��¼������·�д���station���վ�����·�±�
        int minsteps = 1, routesSize = routes.size();//minStepsΪ������Ҫ�����Ĺ���������
        vector<bool>visitedRoute(routesSize, false);//����Ѿ����ʹ�����·
        //������ϣ��ͳ��ÿ��վ����ֵ���·
        for (int i = 0; i < routesSize; ++i)
        {
            for (const auto& station : routes[i])
                hashMap[station].push_back(i);
        }
        while (!myque.empty()) {
            //����ǰ���������е�վ�㶼����Ѱ��һ����·
            for (int i = myque.size(); i > 0; --i)
            {
                int frontstation = myque.front();
                myque.pop();
                //����frontstation���վ�����ܵ����������·
                for (const auto& routeindex : hashMap[frontstation]) {
                    if (!visitedRoute[routeindex]) {//������·������δ���ʹ���
                        visitedRoute[routeindex] = true;
                        //����routeindex������·�е�����վ��
                        for (const auto& station : routes[routeindex]) {
                            if (station == target)//����Ŀ�ĵ�
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