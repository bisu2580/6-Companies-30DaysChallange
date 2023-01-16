#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator)
    {
        string res;
        int64_t sign;
        if (numerator == 0)
        {
            return "0";
        }
        if ((numerator < 0) ^ (denominator < 0))
        {
            res += '-';
        }

        int64_t n = abs(numerator);
        int64_t d = abs(denominator);

        int64_t quotient = n / d;
        int64_t rem = n % d;

        if (rem == 0)
        {
            res += to_string(quotient);
            return res;
        }
        else
        {
            res += to_string(quotient);
            res.push_back('.');
            map<int, int> mp;

            while (rem > 0)
            {
                if (mp.find(rem) != mp.end())
                {
                    int pos = mp[rem];
                    res.insert(pos, "(");
                    res += ')';
                    break;
                }
                else
                {
                    mp[rem] = res.size();
                    rem = (rem * 10);
                    quotient = rem / d;
                    rem = rem % d;
                    res += to_string(quotient);
                }
            }
        }
        return res;
    }
};

int main()
{
    int n = -2147483648;
    int d = 1;
    Solution s;
    string num = s.fractionToDecimal(n, d);
    cout << num.data();
}