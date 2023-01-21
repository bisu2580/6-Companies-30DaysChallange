#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> primesArray(vector<bool> ans)
    {
        vector<int> prime;
        for (int i = 2; i <= 1e6; i++)
        {
            if (!ans[i])
            {
                prime.push_back(i);
                for (int j = i; j <= 1e6; j += i)
                {
                    ans[j] = true;
                }
            }
        }
        return prime;
    }

public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> ans(1e6 + 1, false);
        vector<int> prime = primesArray(ans);
        int mini = INT_MAX;
        int a = -1, b = -1;
        int n = prime.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (prime[i] >= left && prime[i + 1] <= right)
            {
                if (prime[i + 1] - prime[i] < mini)
                {
                    mini = prime[i + 1] - prime[i];
                    a = prime[i];
                    b = prime[i + 1];
                }
            }
        }
        prime.clear();
        prime.push_back(a);
        prime.push_back(b);
        return prime;
    }
};
int main()
{
    int left = 10, right = 19;
    Solution s;
    vector<int> result = s.closestPrimes(left, right);
    cout << "Closest Pair: \n";
    for (auto i : result)
    {
        cout << i << " ";
    }
}