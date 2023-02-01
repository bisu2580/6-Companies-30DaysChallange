#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        int maxi = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (j > 0 && j < col - 1 && i < row - 2)
                {
                    int ans = grid[i][j - 1] + grid[i][j] + grid[i][j + 1] + grid[i + 1][j] + grid[i + 2][j] + grid[i + 2][j - 1] + grid[i + 2][j + 1];
                    maxi = max(maxi, ans);
                }
            }
        }
        return maxi;
    }
};
int main()
{
    vector<vector<int>> nums = {{6, 2, 1, 3}, {4, 2, 1, 5}, {9, 2, 8, 7}, {4, 1, 2, 9}};
    Solution s;
    cout << "Maximum sum is " << s.maxSum(nums);
}