#include<vector>
using namespace std;

//������С·����
//https://www.nowcoder.com/questionTerminal/7d21b6be4c6b429bb92d219341c4f8bb
class Solution {
public:
    /**
     *
     * @param matrix int����vector<vector<>> the matrix
     * @return int����
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int row = matrix.size(), col = matrix[0].size();
        if (row == 0)
            return 0;
        vector<vector<int> >minPath(row, vector<int>(col));
        minPath[0][0] = matrix[0][0];
        //����F(0,0)���ܳ�ʼ��Ϊ0 ��Ϊmatrix[0][0]Ҳ��ֵ
        for (int i = 1; i < row; ++i)//��ʼ����һ��
        {
            minPath[i][0] = matrix[i][0] + minPath[i - 1][0];
        }
        for (int i = 1; i < col; ++i)//��ʼ����һ��
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