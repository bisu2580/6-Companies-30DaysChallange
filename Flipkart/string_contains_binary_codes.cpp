#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {

        if (k > s.size())
        {
            return false;
        }
        unordered_set<string> store;
        int n = s.size();
        for (int i = 0; i <= n - k; i++)
        {
            store.insert(s.substr(i, k));
        }
        if (store.size() == pow(2, k))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    string sp = "00110110";
    int k = 2;
    cout << boolalpha;
    cout << s.hasAllCodes(sp, k);
}