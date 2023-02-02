#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> ans;
    int size;

public:
    Solution(vector<int> &nums)
    {
        ans = nums;
        size = ans.size();
    }

    vector<int> reset()
    {
        return ans;
    }

    vector<int> shuffle()
    {
        vector<int> finArray = ans;
        int sizeLeft = size;
        for (int i = size - 1; i >= 0; i--)
        {
            int num = rand() % sizeLeft;
            swap(finArray[num], finArray[i]);
            sizeLeft--;
        }
        return finArray;
    }
};
