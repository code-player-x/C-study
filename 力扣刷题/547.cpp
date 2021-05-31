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
            parent[x] = parent[parent[x]];//路径减半优化
            x = parent[x];
        }
        return x;
    }

    void Union(vector<int>& parent, int x, int y)
    {
        parent[Find(parent, x)] = Find(parent, y);
    }

    //把index1祖先结点的父亲设置为index2的祖先
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<int>parent(cities);

        //初始化并查集
        for (int i = 0; i < cities; ++i)
        {
            parent[i] = i;
        }
        //因为是无向图，邻接矩阵是对称的
        for (int i = 0; i < cities; ++i)
        {
            for (int j = i + 1; j < cities; ++j)
            {
                if (isConnected[i][j] == 1)
                    Union(parent, i, j);
            }
        }
        //统计联通图个数
        int pro = 0;
        for (int i = 0; i < cities; ++i)
        {
            if (parent[i] == i)
                pro++;
        }
        return pro;

    }
};