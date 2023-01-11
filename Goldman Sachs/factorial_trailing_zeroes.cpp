#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int trailingZeroes(int n)
    {
        if (n == 0 || n == 1)
        {
            return 0;
        }
        int count = 0;
        while (n >= 5)
        {
            n /= 5;
            count += n;
        }
        return count;
    }
};
int main()
{
    int num = 5;
    Solution s;
    cout << "Number of trailing zeroes in " << num << "! is " << s.trailingZeroes(num);
}