#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> a(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int x = -k; x <= k; x++)
                {
                    if (i + x >= 0 && i + x < row)
                    {
                        int left = max(j - k, 0);
                        int right = j + k + 1;
                        a[i + x][left] += mat[i][j];
                        if (right < col)
                            a[i + x][right] -= mat[i][j];
                    }
                }
            }
        }
        int sum;
        for (int i = 0; i < row; i++)
        {
            sum = 0;
            for (int j = 0; j < col; j++)
            {
                sum += a[i][j];
                a[i][j] = sum;
            }
        }
        return a;
    }
};
int main()
{
    vector<vector<int>> num = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    vector<vector<int>> res = s.matrixBlockSum(num, 1);
    cout << "Sum is \n";
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}