#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {

        if (nums.size() < 3)
            return false;
        int a = INT_MAX, b = INT_MAX;

        for (auto x : nums)
        {
            if (x > b)
                return true;
            if (x > a)
            {
                b = min(b, x);
            }
            a = min(a, x);
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << boolalpha;
    cout << s.increasingTriplet(nums);
}