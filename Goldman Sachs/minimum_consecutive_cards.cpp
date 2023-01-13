#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        // used for storing elements and their indexes
        unordered_map<int, int> m;

        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++)
        {
            /*used to find a particular value in map. If previously present then count the diff
            between first and last occurance and add 1 to find no of elements*/
            if (m.find(cards[i]) != m.end())
            {
                ans = min(ans, i - m[cards[i]] + 1);
            }
            m[cards[i]] = i;
        }
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
int main()
{
    vector<int> cards = {3, 4, 2, 3, 4, 7};
    Solution s;
    cout << "Minimum consecutive cards- " << s.minimumCardPickup(cards);
}