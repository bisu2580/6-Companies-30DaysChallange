#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int size = matrix.size();
        int mini = INT_MAX;
        int count = 0;
        long long int sum = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int pos = abs(matrix[i][j]);
                mini = min(mini, pos);
                if (matrix[i][j] < 0)
                {
                    count++;
                }
                sum += pos;
            }
        }
        if (count % 2 == 0)
        {
            return sum;
        }
        return sum - 2 * mini;
    }
};
int main()
{
    vector<vector<int>> num = {{1, -1}, {-1, 1}};
    Solution s;
    cout << "Maximum sum is " << s.maxMatrixSum(num);
}