//547https://leetcode-cn.com/problems/number-of-provinces/

class Solution {
public:

    int Find(vector<int>& parent, int x)
    {
        // if(parent[index]!=index)
        // {
        //     parent[index]=Find(parent,parent[index]);
        // }
        // return parent[index];
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];//·�������Ż�
            x = parent[x];
        }
        return x;
    }

    void Union(vector<int>& parent, int x, int y)
    {
        parent[Find(parent, x)] = Find(parent, y);
    }

    //��index1���Ƚ��ĸ�������Ϊindex2������
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<int>parent(cities);

        //��ʼ�����鼯
        for (int i = 0; i < cities; ++i)
        {
            parent[i] = i;
        }
        //��Ϊ������ͼ���ڽӾ����ǶԳƵ�
        for (int i = 0; i < cities; ++i)
        {
            for (int j = i + 1; j < cities; ++j)
            {
                if (isConnected[i][j] == 1)
                    Union(parent, i, j);
            }
        }
        //ͳ����ͨͼ����
        int pro = 0;
        for (int i = 0; i < cities; ++i)
        {
            if (parent[i] == i)
                pro++;
        }
        return pro;

    }
};