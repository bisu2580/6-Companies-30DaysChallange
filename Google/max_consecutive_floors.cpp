#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        sort(special.begin(), special.end());
        int leftcount = special[0] - bottom;
        int midDiff = 0;
        bottom = special[0];
        for (int i = 1; i < special.size(); i++)
        {
            leftcount = max(leftcount, special[i] - bottom - 1);
            bottom = special[i];
        }
        return max(leftcount, top - bottom);
    }
};
int main()
{
    int bottom = 3, top = 15;
    vector<int> special = {7, 9, 13};
    Solution s;
    cout << "Maximum consecutive: " << s.maxConsecutive(bottom, top, special);
}