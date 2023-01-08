#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        int start = 0, end = n - 1;
        while (start + 1 < n && nums[start] <= nums[start + 1])
        {
            start++;
        }
        while (end - 1 >= 0 && nums[end - 1] <= nums[end])
        {
            end--;
        }
        if (start == n - 1)
        {
            return 0;
        }
        for (int i = start; i <= end; i++)
        {
            mini = min(nums[i], mini);
            maxi = max(nums[i], maxi);
        }
        while (start - 1 >= 0 && nums[start - 1] > mini)
        {
            start--;
        }
        while (end + 1 <= n - 1 && nums[end + 1] < maxi)
        {
            end++;
        }

        return end - start + 1;
    }
};

int main()
{
    vector<int> num = {2, 6, 4, 8, 10, 9, 15};
    Solution s;
    cout << "Length is " << s.findUnsortedSubarray(num);
}