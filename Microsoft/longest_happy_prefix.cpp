#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPrefix(string s)
    {

        int n = s.size();
        vector<int> num(n, 0);
        int left = 0, right = 1;

        while (right < n)
        {
            if (s[left] == s[right])
            {
                num[right] = left + 1;
                left++;
                right++;
            }
            else if (left > 0)
            {
                left = num[left - 1];
            }
            else
            {
                right++;
            }
        }

        return s.substr(0, left);
    }
};
int main()
{
    string s = "ababab";
    Solution sol;
    s = sol.longestPrefix(s);
    cout << s;
}