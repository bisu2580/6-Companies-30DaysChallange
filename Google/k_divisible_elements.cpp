#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        set<string> st;
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            string s;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] % p == 0)
                {
                    cnt++;
                }
                if (cnt > k)
                {
                    break;
                }
                s.push_back(nums[j] + '0');
                st.insert(s);
            }
        }
        return st.size();
    }
};
int main()
{
    vector<int> nums = {2, 3, 3, 2, 2};
    Solution s;
    cout << "No of distinct subarrays: " << s.countDistinct(nums, 2, 2);
}