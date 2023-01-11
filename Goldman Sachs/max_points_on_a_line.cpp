#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int row = points.size();

        if (row <= 2)
        {
            return row;
        }
        int maxi = 2;
        for (int i = 0; i < row; i++)
        {
            for (int j = i + 1; j < row; j++)
            {
                int count = 2;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                for (int k = 0; k < row; k++)
                {
                    int xk = points[k][0];
                    int yk = points[k][1];
                    if (k != i && k != j)
                    {
                        if ((yk - y1) * (x2 - xk) == (y2 - yk) * (xk - x1))
                        {
                            count++;
                        }
                    }
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};
int main()
{
    vector<vector<int>> num = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    Solution s;
    cout << "Max points in the lines are " << s.maxPoints(num);
}