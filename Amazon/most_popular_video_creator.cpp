#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    struct video
    {
        long sum = 0;
        string small;
        int max_view = 0;
    };

public:
    vector<vector<string>> mostPopularCreator(vector<string> &c, vector<string> &ids, vector<int> &views)
    {
        unordered_map<string, video> mp;
        long count = 0;
        for (int i = 0; i < c.size(); i++)
        {
            if (!mp.count(c[i]))
            {
                mp[c[i]] = {views[i], ids[i], views[i]};
                count = max(count, mp[c[i]].sum);
                continue;
            }
            mp[c[i]].sum += views[i];
            if (mp[c[i]].max_view < views[i] || mp[c[i]].max_view == views[i] && ids[i] < mp[c[i]].small)
            {
                mp[c[i]].max_view = views[i];
                mp[c[i]].small = ids[i];
            }
            count = max(count, mp[c[i]].sum);
        }
        vector<vector<string>> ans;
        for (auto &k : mp)
        {
            if (k.second.sum == count)
                ans.push_back({k.first, k.second.small});
        }
        return ans;
    }
};
int main()
{
    vector<string> creators = {"alice", "bob", "alice", "chris"}, ids = {"one", "two", "three", "four"};
    vector<int> views = {5, 10, 5, 4};
    Solution s;
    cout << "List of popular creators\n";
    vector<vector<string>> ans = s.mostPopularCreator(creators, ids, views);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}