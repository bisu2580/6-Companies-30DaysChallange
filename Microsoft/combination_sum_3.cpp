#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void generate(vector<vector<int>> &ans, int n, int k, vector<int> res, int start)
    {

        if (n < 0 || k < 0)
        {
            return;
        }
        if (n == 0 && k == 0)
        {
            ans.push_back(res);
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            res.push_back(i);
            generate(ans, n - i, k - 1, res, i + 1);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> res;
        vector<vector<int>> ans;
        generate(ans, n, k, res, 1);
        return ans;
    }
};
int main()
{
    int k = 3, n = 7;
    Solution s;
    vector<vector<int>> result = s.combinationSum3(k, n);

    cout << "The combination(s) is/are \n";

    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << ",";
        }
        cout << endl;
    }
}