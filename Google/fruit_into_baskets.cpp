#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        set<int> s;
        for (auto i : fruits)
        {
            s.insert(i);
        }
        if (s.size() <= 2)
            return fruits.size();
        fruits.push_back(1e5 + 1);
        int size = fruits.size();
        int j = 0, totalDiffFruits = 0;
        vector<int> f(1e5 + 5);
        int maxi = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            if (f[fruits[i]] == 0 && totalDiffFruits == 2)
            {
                maxi = max(maxi, (i - j));
                while (j < i)
                {
                    if (f[fruits[j]] > 1)
                    {
                        f[fruits[j]]--;
                        j++;
                    }
                    else if (f[fruits[j]] == 1)
                    {
                        f[fruits[j]]--;
                        j++;
                        break;
                    }
                }
                f[fruits[i]]++;
            }
            else if (f[fruits[i]] == 0)
            {
                totalDiffFruits++;
                f[fruits[i]]++;
            }
            else
            {
                f[fruits[i]]++;
            }
        }
        return maxi;
    }
};
int main()
{
    vector<int> fruits = {1, 2, 3, 2, 2};
    Solution s;
    cout << "Maximum fruits: " << s.totalFruit(fruits);
}