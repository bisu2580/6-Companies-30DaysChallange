#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
#define mod 1000000007
    int topDown(int s, int e, int curr, int k, int dp[][1001])
    {
        if (k == 0)
        {
            if (curr == e)
                return 1;
            else
                return 0;
        }
        if (dp[curr + 1001][k] != -1)
        {
            return dp[curr + 1001][k];
        }
        int rightMove = topDown(s, e, curr + 1, k - 1, dp) % mod;
        int leftMove = topDown(s, e, curr - 1, k - 1, dp) % mod;

        return dp[curr + 1001][k] = (rightMove + leftMove) % mod;
    }

    int numberOfWays(int s, int e, int k)
    {
        int dp[3002][1001];
        for (int i = 0; i < 3002; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                dp[i][j] = -1;
            }
        }
        return topDown(s, e, s, k, dp);
    }
};
int main()
{
    int startPos = 1, endPos = 2, k = 3;
    Solution s;
    cout << "No of ways= \n";
    cout << s.numberOfWays(startPos, endPos, k);
}