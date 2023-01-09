#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int left = 0;
        int count = 0;
        vector<int> num(3, 0);
        for (int right = 0; right < s.size(); right++)
        {
            num[s[right] - 'a']++;
            while (num[0] > 0 && num[1] > 0 && num[2] > 0 && left <= right)
            {
                num[s[left] - 'a']--;
                count += (s.size() - right);
                left++;
            }
        }
        return count;
    }
};
int main()
{
    string num = "abcabc";
    Solution s;
    cout << s.numberOfSubstrings(num);
}