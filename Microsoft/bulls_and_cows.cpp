#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0, cows = 0;
        vector<int> num(10, 0);
        for (int i = 0; i < secret.size(); i++)
        {
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if (s == g)
            {
                bulls++;
            }
            else
            {
                if (num[s] < 0)
                    cows++;
                if (num[g] > 0)
                    cows++;
                num[s]++;
                num[g]--;
            }
        }
        string b = to_string(bulls);
        string c = to_string(cows);
        return b + "A" + c + "B";
    }
};
int main()
{
    string secret = "1807";
    string guess = "7810";
    Solution s;
    string res = s.getHint(secret, guess);
    cout << res;
}