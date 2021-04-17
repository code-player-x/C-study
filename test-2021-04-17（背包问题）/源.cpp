//链接：https://www.nowcoder.com/questionTerminal/3ee42c9155c340588729995561ace594
//来源：牛客网
//此文件为背包问题的学习代码，具体题目详见链接
#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int N, V;
    while (cin >> N >> V)
    {
        vector<int> value(N);//存储每个物品的价值
        vector<int> capacity(N);//存储每个物品的容量
        for (int i = 0; i < N; ++i)
        {
            cin >> value[i] >> capacity[i];
        }
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
        //有N+1行，但是从1开始遍历，所以每行表示每个物品
        //有V+1列，但是从1开始遍历，所以每列表示从1开始到最大容量 的 各种情况下 的 物品最大价值存储
        for (int i = 1; i < N + 1; ++i)
        {
            for (int j = 1; j < V + 1; ++j)
            {
                if (capacity[i - 1] > j)//如果不下，那就等于上次的最优存储
                {//这里的capacity[i-1]是因为这里的i从1开始
                    dp[i][j] = dp[i - 1][j];
                }
                else//如果能放下，有两种情况：1、放 2、不放
                    //放和不放取决于放了之后是否是最优的，于是创建一个临时变量。
                {//dp[i-1][j-capacity[i-1]]：i-1：上面一行，j-capacity[i-1]：装了i-1这个物品之后还剩的容量。所以整体就是：当前的tmp_best == 装了i-1物品的价值 + 装了这个物品后剩余的容量还可以装的最优的方案
                    int tmp_best = value[i - 1] + dp[i - 1][j - capacity[i - 1]];
                    dp[i][j] = max(tmp_best, dp[i - 1][j]);
                }
            }
        }
        //返回最后一个元素就是最优的方案
        cout << dp[N][V] << endl;
    }
    return 0;
}