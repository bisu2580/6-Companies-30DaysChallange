#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        long long a = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (a < asteroids[i])
            {
                return false;
            }
            a += asteroids[i];
        }
        return true;
    }
};
int main()
{
    int mass = 10;
    vector<int> asteroids = {3, 9, 19, 5, 21};
    cout << boolalpha;
    Solution s;
    cout << s.asteroidsDestroyed(mass, asteroids);
}