#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (nums1 == nums2)
        {
            return m;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    Solution s;
    cout << "Maximum length: " << s.findLength(nums1, nums2);
}