//链接：https://www.nowcoder.com/questionTerminal/11ee0516a988421abf40b315a2b28d08?f=discussion&toCommentId=9311805
//来源：牛客网

//参考资料https://blog.nowcoder.net/n/81d04b3aaa1649ecba210ea6cbfccf84
#include <iostream>
#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
const int MAXN = 10000010;

int ans;
int maxRoom;
int pre[MAXN];
int res[MAXN];
int root;

int find(int x) {
    while (x != pre[x]) {
        pre[x] = pre[pre[x]];
        x = pre[x];
    }
    return x;
}

void join(int x, int y)
{
    if (x > maxRoom)
    {
        maxRoom = x;
    }
    if (y > maxRoom)
    {
        maxRoom = y;
    }

    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        pre[fx] = fy;
        res[fy] += res[fx];
    }
    return;
}

int main(int argc, const char* argv[])
{
    int n;
    int A, B;
    int t;
    while (cin >> t) {
        while (cin >> n)
        {
            mem(res, 0);//把res全部初始化为0
            ans = 0;
            maxRoom = 0;
            for (int i = 0; i <= MAXN; i++) {
                pre[i] = i;
                res[i] = 1;
            }
            for (int i = 0; i < n; i++) {
                scanf("%d%d", &A, &B);
                join(A, B);
            }
            for (int i = 0; i <= maxRoom; i++) {
                if (res[i] > ans)
                {
                    ans = res[i];
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}