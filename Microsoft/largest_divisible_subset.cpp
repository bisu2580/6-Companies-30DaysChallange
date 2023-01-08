#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        vector<int> dp(n + 1, 1);
        int maxi = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    if (dp[i] > maxi)
                    {
                        maxi = dp[i];
                    }
                }
            }
        }
        int prev = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (dp[i] == maxi && (prev % nums[i] == 0 || prev == -1))
            {
                ans.push_back(nums[i]);
                maxi -= 1;
                prev = nums[i];
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1, 2, 4, 8};
    Solution s;
    nums = s.largestDivisibleSubset(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
}