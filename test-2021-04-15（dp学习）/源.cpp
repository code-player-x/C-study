#include<vector>
using namespace std;

//矩阵最小路径和
//https://www.nowcoder.com/questionTerminal/7d21b6be4c6b429bb92d219341c4f8bb
class Solution {
public:
    /**
     *
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int row = matrix.size(), col = matrix[0].size();
        if (row == 0)
            return 0;
        vector<vector<int> >minPath(row, vector<int>(col));
        minPath[0][0] = matrix[0][0];
        //这里F(0,0)不能初始化为0 因为matrix[0][0]也有值
        for (int i = 1; i < row; ++i)//初始化第一列
        {
            minPath[i][0] = matrix[i][0] + minPath[i - 1][0];
        }
        for (int i = 1; i < col; ++i)//初始化第一行
        {
            minPath[0][i] = matrix[0][i] + minPath[0][i - 1];
        }
        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                minPath[i][j] = min(minPath[i - 1][j], minPath[i][j - 1]) + matrix[i][j];

            }
        }
        return minPath[row - 1][col - 1];
    }
};