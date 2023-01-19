#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int calSteps(int n, long n1, long n2)
    {
        int steps = 0;
        long res = static_cast<long>(n);
        while (n1 <= res)
        {
            steps += min(res + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
    int findKthNumber(int n, int k)
    {
        int num = 1;
        k--;
        while (k > 0)
        {
            int nxt = calSteps(n, num, num + 1);
            if (nxt <= k)
            {
                num += 1;
                k -= nxt;
            }
            else
            {
                num *= 10;
                k--;
            }
        }
        return num;
    }
};
int main()
{
    int n = 13, k = 2;
    Solution s;
    cout << "kth smallest element: " << s.findKthNumber(n, k);
}