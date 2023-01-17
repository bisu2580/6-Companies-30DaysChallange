#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findIntegers(int n)
    {
        int fib[31];
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i < 30; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        int ans = 0, count = 30, prev = false;

        while (count >= 0)
        {
            if (n & (1 << count))
            {
                ans += fib[count];
                if (prev == true)
                {
                    return ans;
                }
                prev = true;
            }
            else
            {
                prev = false;
            }
            count--;
        }
        return ans + 1;
    }
};
int main()
{
    int n = 5;
    Solution s;
    cout << s.findIntegers(n);
}