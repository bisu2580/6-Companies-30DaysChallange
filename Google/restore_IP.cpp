#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void getIP(vector<string> &temp, vector<string> &IP, string &s, int index)
    {
        if (index == s.length() && temp.size() == 4)
        {
            string valid = temp[0] + '.' + temp[1] + '.' + temp[2] + '.' + temp[3];
            IP.push_back(valid);
            return;
        }
        string tempStr = "";
        for (int i = index; i < s.length() && temp.size() < 4; i++)
        {
            if (s[i] - '0' > 9)
                continue;
            tempStr += s[i];
            int tempInt = stoi(tempStr);

            if (tempInt >= 0 && tempInt <= 255)
            {
                temp.push_back(tempStr);
                getIP(temp, IP, s, i + 1);
                temp.pop_back();
            }
            if (tempInt <= 0 || tempInt > 255)
            {
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> IP;
        vector<string> temp;
        getIP(temp, IP, s, 0);
        return IP;
    }
};
int main()
{
    string num = "25525511135";
    Solution s;
    vector<string> ans = s.restoreIpAddresses(num);
    cout << "All possible strings:\n";
    for (auto i : ans)
    {
        cout << i << endl;
    }
}