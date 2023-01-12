#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int distanceCal(vector<int> &p1, vector<int> &p2)
    {
        int left = p2[0] - p1[0];
        int right = p2[1] - p1[1];
        return left * left + right * right;
    }

public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int count = 0;
        int n = points.size();

        for (int i = 0; i < n; i++)
        {
            map<int, int> res;
            for (int j = 0; j < n; j++)
            {
                int dist = distanceCal(points[i], points[j]);
                res[dist]++;
            }
            for (auto i : res)
            {
                auto num = i.second;
                if (num)
                {
                    count += (num * (num - 1));
                }
            }
        }
        return count;
    }
};
int main()
{
    vector<vector<int>> num = {{0, 0}, {1, 0}, {2, 0}};
    Solution s;
    cout << "Number of boomerangs: " << s.numberOfBoomerangs(num);
}