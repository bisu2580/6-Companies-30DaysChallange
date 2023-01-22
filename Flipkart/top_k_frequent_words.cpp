#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        map<string, int> mp;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            mp[words[i]]++;
        }
        priority_queue<pair<int, string>> pq;

        for (auto &it : mp)
        {
            pq.push(make_pair(-it.second, it.first));
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<pair<int, string>> candidate;
        while (!pq.empty())
        {
            candidate.emplace_back(pq.top());
            pq.pop();
        }
        sort(candidate.begin(), candidate.end());
        vector<string> ans;
        for (int i = 0; i < candidate.size(); i++)
        {
            ans.push_back(candidate[i].second);
        }
        return ans;
    }
};
int main()
{

    vector<string> ans = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    Solution s;
    ans = s.topKFrequent(ans, k);
    cout << "Top " << k << "Frequent words string: \n";
    for (auto i : ans)
    {
        cout << i << " ";
    }
}