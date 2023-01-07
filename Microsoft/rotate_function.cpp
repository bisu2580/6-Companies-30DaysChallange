#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time-O(n) space-O(1)
    int maxRotateFunction(vector<int> &nums)
    {
        int size = nums.size();
        int maxi, sum_of_array = 0, cumulative_sum = 0;
        // calculate the sum of array
        for (int i = 0; i < size; i++)
        {
            sum_of_array += nums[i];
        }
        // cumulative sum
        for (int j = 0; j < size; j++)
        {
            cumulative_sum += (j * nums[j]);
        }
        int max_value = cumulative_sum;
        for (int i = 1; i < size; i++)
        {
            cumulative_sum += (sum_of_array - (size * nums[size - i]));
            max_value = max(max_value, cumulative_sum);
        }
        return max_value;
    }
};
int main()
{
    vector<int> nums = {4, 3, 2, 6};
    Solution sol;
    cout << sol.maxRotateFunction(nums);
}