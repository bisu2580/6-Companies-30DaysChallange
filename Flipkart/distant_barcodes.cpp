#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto i : barcodes)
        {
            mp[i]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        int prev = INT_MIN;
        while (!pq.empty())
        {
            if (prev == pq.top().second)
            {
                pair<int, int> firstMax = pq.top();
                pq.pop();
                pair<int, int> secondMax = pq.top();
                ans.push_back(secondMax.second);
                pq.pop();
                secondMax.first--;
                if (secondMax.first > 0)
                {
                    pq.push({secondMax.first, secondMax.second});
                }
                pq.push(firstMax);
                prev = secondMax.second;
            }
            else
            {

                pair<int, int> firstMax = pq.top();
                pq.pop();
                prev = firstMax.second;
                ans.push_back(firstMax.second);
                firstMax.first--;

                if (firstMax.first > 0)
                {
                    pq.push({firstMax.first, firstMax.second});
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 2};
    Solution s;
    nums = s.rearrangeBarcodes(nums);
    cout << "Modified barcodes: \n";
    for (auto i : nums)
    {
        cout << i << " ";
    }
}