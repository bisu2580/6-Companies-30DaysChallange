#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        map<pair<int, int>, int> mp;
        for (auto i : rectangles)
        {
            mp[{i[0], i[1]}]++;
            mp[{i[2], i[3]}]++;
            mp[{i[0], i[3]}]--;
            mp[{i[2], i[1]}]--;
        }
        int count = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (abs(it->second) == 1)
                count++;
            else if (it->second != 0 && abs(it->second) != 1)
                return false;
        }
        if (count == 4)
            return true;

        return false;
    }
};
int main()
{
    vector<vector<int>> nums = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
    Solution s;
    cout << boolalpha;
    cout << s.isRectangleCover(nums);
}