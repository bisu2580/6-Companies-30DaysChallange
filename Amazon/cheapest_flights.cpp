#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto i : flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > k)
                continue;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int width = iter.second;

                if (cost + width < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + width;
                    q.push({stops + 1, {adjNode, cost + width}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};
int main()
{
    int n = 4;
    vector<vector<int>> nums = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    Solution s;
    cout << "Cheapest price: " << s.findCheapestPrice(n, nums, 0, 3, 1);
}