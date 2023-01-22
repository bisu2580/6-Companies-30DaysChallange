#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool dfs(vector<int> &nums, int k, int targetSum, int currSum, vector<bool> &visited, int idx)
    {
        if (k == 0)
            return true;
        if (currSum > targetSum)
            return false;
        if (currSum == targetSum)
        {
            return dfs(nums, k - 1, targetSum, 0, visited, 0);
        }
        for (int i = idx; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                if (dfs(nums, k, targetSum, currSum + nums[i], visited, i + 1))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0, maxNum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxNum = max(maxNum, nums[i]);
        }
        if (sum % k != 0 || maxNum > sum / k)
        {
            return false;
        }
        vector<bool> ans(nums.size(), false);
        return dfs(nums, k, sum / k, 0, ans, 0);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    cout << boolalpha;
    cout << "Possible: " << s.canPartitionKSubsets(nums, k);
}