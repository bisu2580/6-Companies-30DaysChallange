#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        vector<string> name;
        vector<string> city;
        vector<string> ans;
        vector<int> time;
        vector<int> amount;
        int test = 0;

        for (auto s : transactions)
        {
            stringstream ss(s);
            string st;

            while (getline(ss, st, ','))
            {
                if (test == 0)
                {
                    name.emplace_back(st);
                    test = 1;
                }
                else if (test == 1)
                {
                    time.emplace_back(stoi(st));
                    test = 2;
                }
                else if (test == 2)
                {
                    amount.emplace_back(stoi(st));
                    test = 3;
                }
                else if (test == 3)
                {
                    city.emplace_back(st);
                    test = 0;
                }
            }
        }

        int index = 0;
        for (auto i : amount)
        {
            if (i > 1000)
            {
                ans.emplace_back(transactions[index]);
            }
            index++;
        }

        for (int i = 0; i < transactions.size(); i++)
        {
            for (int j = 0; j < transactions.size(); j++)
            {
                if (name[i] == name[j] && city[i] != city[j])
                {
                    if (abs(time[i] - time[j]) <= 60)
                    {
                        if (amount[i] <= 1000)
                        {
                            ans.emplace_back(transactions[i]);
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<string> transactions = {"alice,20,800,mtv", "alice,50,100,beijing"};
    Solution s;
    vector<string> ans = s.invalidTransactions(transactions);
    cout << "Invalid choice is: \n[";
    for (auto i : ans)
    {
        cout << i << ",";
    }
    cout << "]";
}