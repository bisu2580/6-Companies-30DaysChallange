#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int gcd(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        return gcd(b % a, a);
    }
    int findGcd(vector<int> &numsDivide)
    {
        int res = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++)
        {
            res = gcd(numsDivide[i], res);
            if (res == 1)
            {
                return 1;
            }
        }
        return res;
    }

public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        sort(nums.begin(), nums.end());
        int factor = findGcd(numsDivide);
        for (int i = 0; i < nums.size(); i++)
        {
            if (factor % nums[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums = {2, 3, 2, 4, 3};
    vector<int> numsDivide = {9, 6, 9, 3, 15};
    Solution s;
    cout << "Minimum deletions: " << s.minOperations(nums, numsDivide);
}