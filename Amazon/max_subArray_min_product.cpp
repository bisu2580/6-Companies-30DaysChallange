#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
#define mod 1000000007
#define ll long long

    ll getSum(vector<ll> &sum, int left, int right)
    {
        return sum[right + 1] - sum[left];
    }

    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n), right(n);
        vector<ll> sum(n + 1, 0);
        stack<int> s1, s2;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (!s1.empty() && nums[s1.top()] >= nums[i])
            {
                s1.pop();
            }
            if (!s1.empty())
            {
                left[i] = s1.top() + 1;
            }
            else
            {
                left[i] = 0;
            }

            s1.push(i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s2.empty() && nums[s2.top()] >= nums[i])
            {
                s2.pop();
            }
            if (!s2.empty())
            {
                right[i] = s2.top() - 1;
            }
            else
            {
                right[i] = n - 1;
            }
            s2.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, nums[i] * 1ll * getSum(sum, left[i], right[i]));
        }
        return ans % mod;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 2};
    Solution s;
    cout << "Answer is " << s.maxSumMinProduct(nums);
}