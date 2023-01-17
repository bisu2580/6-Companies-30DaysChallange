#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int n = s.size();
        int m = words.size();
        int count = 0;
        vector<vector<int>> indexes(26);
        for (int i = 0; i < n; i++)
        {
            int index = s[i] - 'a';
            indexes[index].push_back(i);
        }

        for (int i = 0; i < m; i++)
        {
            bool isSub = true;
            int last = -1;
            for (auto w : words[i])
            {
                auto it = upper_bound(indexes[w - 'a'].begin(), indexes[w - 'a'].end(), last);
                if (it == indexes[w - 'a'].end())
                {
                    isSub = false;
                    break;
                }
                else
                {
                    last = *it;
                }
            }
            if (isSub)
            {
                count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    string str = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace"};
    cout << s.numMatchingSubseq(str, words);
}