#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string customSortString(string order, string s)
    {
        string s1, s2;
        vector<int> count(26, 0);
        for (auto i : order)
        {
            count[i - 'a']++;
        }
        for (auto i : s)
        {
            if (count[i - 'a'] == 0)
                s2.push_back(i);
            else
                count[i - 'a']++;
        }
        for (auto i : order)
        {
            while (count[i - 'a'] > 1)
            {
                s1.push_back(i);
                count[i - 'a']--;
            }
        }
        return s1 + s2;
    }
};
int main()
{
    string order = "cba";
    string s = "abcd";
    Solution sol;
    cout << sol.customSortString(order, s);
}