#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
#define ll long long
#define modulo 1000000007
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        ll day = 2;
        vector<array<ll, 3>> persons = {{delay + 1, forget + 1, 1}};
        while (day <= n)
        {
            while (!persons.empty() && persons[0][1] == day)
            {
                persons.erase(persons.begin());
            }
            ll cnt = 0;
            for (auto &x : persons)
            {
                if (x[0] <= day)
                {
                    cnt += x[2];
                }
                cnt %= modulo;
            }
            persons.push_back({day + delay, day + forget, cnt});
            day++;
        }
        ll ans = 0;
        for (auto &x : persons)
        {
            ans += x[2];
            ans %= modulo;
        }
        return ans;
    }
};
int main()
{
    int n = 6, delay = 2, forget = 4;
    Solution s;
    cout << "No of people who know secret: " << s.peopleAwareOfSecret(n, delay, forget);
}