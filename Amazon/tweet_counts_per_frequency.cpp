#include <bits/stdc++.h>
using namespace std;
class TweetCounts
{
public:
    unordered_map<string, vector<int>> m;
    TweetCounts()
    {
        m.clear();
    }

    void recordTweet(string tweetName, int time)
    {
        m[tweetName].push_back(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
    {

        if (freq == "minute")
        {
            vector<int> ans((endTime - startTime) / 60 + 1, 0);
            for (auto x : m[tweetName])
            {
                if (x >= startTime && x <= endTime)
                    ans[(x - startTime) / 60]++;
            }
            return ans;
        }
        else if (freq == "hour")
        {
            vector<int> ans((endTime - startTime) / 3600 + 1, 0);
            for (auto x : m[tweetName])
            {
                if (x >= startTime && x <= endTime)
                    ans[(x - startTime) / 3600]++;
            }
            return ans;
        }
        else
        {
            int s = 24 * 3600;
            vector<int> ans((endTime - startTime) / s + 1, 0);
            for (auto x : m[tweetName])
            {
                if (x >= startTime && x <= endTime)
                    ans[(x - startTime) / s]++;
            }
            return ans;
        }
    }
};