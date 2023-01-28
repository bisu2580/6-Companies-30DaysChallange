#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    string convertToNary(int num, int base)
    {
        string res;
        while (num > 0)
        {
            int rem = num % base;
            res.push_back(rem + '0');
            num /= base;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool isPalin(string res)
    {
        int left = 0;
        int right = res.size() - 1;
        while (left <= right)
        {
            if (res[left++] != res[right--])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isStrictlyPalindromic(int n)
    {

        bool finRes = true;
        for (int i = 2; i <= n - 2; i++)
        {
            string palin = convertToNary(n, i);
            if (!isPalin(palin))
            {
                finRes = false;
            }
        }
        return finRes;
    }
};
int main()
{
    int num = 9;
    Solution s;
    cout << boolalpha;
    cout << s.isStrictlyPalindromic(num);
}