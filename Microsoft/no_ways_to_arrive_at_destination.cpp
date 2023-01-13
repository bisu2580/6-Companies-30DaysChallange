#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<long long, long long>> adj[n];
        for (auto i : roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int modulo = 1e9 + 7;
        while (!pq.empty())
        {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                long long adjNode = it.first;
                long long edw = it.second;
                if (dis + edw < dist[adjNode])
                {
                    dist[adjNode] = dis + edw;
                    ways[adjNode] = ways[node];
                    pq.push({dis + edw, adjNode});
                }
                else if (dis + edw == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % modulo;
                }
            }
        }
        return ways[n - 1] % modulo;
    }
};
int main()
{
    vector<vector<int>> num = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    Solution s;
    cout << "No of ways to arrive: " << s.countPaths(7, num);
}