//���ӣ�https://www.nowcoder.com/questionTerminal/3ee42c9155c340588729995561ace594
//��Դ��ţ����
//���ļ�Ϊ���������ѧϰ���룬������Ŀ�������
#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int N, V;
    while (cin >> N >> V)
    {
        vector<int> value(N);//�洢ÿ����Ʒ�ļ�ֵ
        vector<int> capacity(N);//�洢ÿ����Ʒ������
        for (int i = 0; i < N; ++i)
        {
            cin >> value[i] >> capacity[i];
        }
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
        //��N+1�У����Ǵ�1��ʼ����������ÿ�б�ʾÿ����Ʒ
        //��V+1�У����Ǵ�1��ʼ����������ÿ�б�ʾ��1��ʼ��������� �� ��������� �� ��Ʒ����ֵ�洢
        for (int i = 1; i < N + 1; ++i)
        {
            for (int j = 1; j < V + 1; ++j)
            {
                if (capacity[i - 1] > j)//������£��Ǿ͵����ϴε����Ŵ洢
                {//�����capacity[i-1]����Ϊ�����i��1��ʼ
                    dp[i][j] = dp[i - 1][j];
                }
                else//����ܷ��£������������1���� 2������
                    //�źͲ���ȡ���ڷ���֮���Ƿ������ŵģ����Ǵ���һ����ʱ������
                {//dp[i-1][j-capacity[i-1]]��i-1������һ�У�j-capacity[i-1]��װ��i-1�����Ʒ֮��ʣ������������������ǣ���ǰ��tmp_best == װ��i-1��Ʒ�ļ�ֵ + װ�������Ʒ��ʣ�������������װ�����ŵķ���
                    int tmp_best = value[i - 1] + dp[i - 1][j - capacity[i - 1]];
                    dp[i][j] = max(tmp_best, dp[i - 1][j]);
                }
            }
        }
        //�������һ��Ԫ�ؾ������ŵķ���
        cout << dp[N][V] << endl;
    }
    return 0;
}