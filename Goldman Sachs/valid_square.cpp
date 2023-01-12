#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int calculateDistance(vector<int> a, vector<int> b)
    {
        return ((b[0] - a[0]) * (b[0] - a[0])) + ((b[1] - a[1]) * (b[1] - a[1]));
    }

public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        set<int> res;
        res.insert(calculateDistance(p1, p2));
        res.insert(calculateDistance(p1, p3));
        res.insert(calculateDistance(p1, p4));
        res.insert(calculateDistance(p2, p3));
        res.insert(calculateDistance(p2, p4));
        res.insert(calculateDistance(p3, p4));

        if (res.size() != 2)
        {
            return false;
        }
        for (auto i : res)
        {
            if (i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    vector<int> p1 = {0, 0};
    vector<int> p2 = {1, 1};
    vector<int> p3 = {1, 0};
    vector<int> p4 = {0, 1};
    Solution s;
    cout << boolalpha;
    cout << s.validSquare(p1, p2, p3, p4);
}