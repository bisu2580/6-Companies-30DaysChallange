#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int res = 0;
        sort(piles.begin(), piles.end(), greater<int>());
        int size = piles.size();
        for (int i = 0; i < size; i += 2)
        {
            res += piles[i + 1];
            size--;
        }
        return res;
    }
};
int main()
{
    vector<int> piles = {2, 4, 1, 2, 7, 8};
    Solution s;
    cout << "Max coins- " << s.maxCoins(piles);
}