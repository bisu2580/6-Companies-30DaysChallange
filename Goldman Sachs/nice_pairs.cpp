#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rev(int num)
    {
        int reverse = 0;
        while (num)
        {
            int rem = num % 10;
            reverse = reverse * 10 + rem;
            num /= 10;
        }
        return reverse;
    }
    int countNicePairs(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        int mod = 1e9 + 7;
        unordered_map<int, int> mp;
        for (int i = n - 1; i >= 0; i--)
        {
            int diff = nums[i] - rev(nums[i]);
            if (mp.count(diff) == true)
            {
                ans = (ans + mp[diff]) % mod;
            }
            mp[diff]++;
        }

        return ans;
    }
};
int main()
{
    vector<int> nums = {42, 11, 1, 97};
    Solution s;
    cout << "No of nice pairs: " << s.countNicePairs(nums);
}