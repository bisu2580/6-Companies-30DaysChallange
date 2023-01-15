#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> &parent, vector<vector<int>> &adj, vector<int> &distance, int p, int d)
    {
        distance[node] = d;
        parent[node] = p;
        for (int v : adj[node])
        {
            if (v != p)
            {
                dfs(v, parent, adj, distance, node, d + 1);
            }
        }
    }
    int maximum_distance(int node, vector<int> &amount, int p, vector<vector<int>> &adj)
    {
        int ret = amount[node];
        int maxi = INT_MIN;
        for (int v : adj[node])
        {
            if (v != p)
            {
                maxi = max(maxi, maximum_distance(v, amount, node, adj));
            }
        }
        if (maxi == INT_MIN)
        {
            return ret;
        }
        return ret + maxi;
    }
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> parent(n);
        vector<int> distance(n);
        dfs(0, parent, adj, distance, 0, 0);

        int curr = bob;
        int bob_distance = 0;
        while (curr != 0)
        {
            if (distance[curr] > bob_distance)
            {
                amount[curr] = 0;
            }
            else if (distance[curr] == bob_distance)
            {
                amount[curr] /= 2;
            }
            curr = parent[curr];
            bob_distance++;
        }
        return maximum_distance(0, amount, 0, adj);
    }
};
int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    int bob = 3;
    vector<int> amount = {-2, 4, 2, -4, 6};
    Solution s;
    cout << "Maximum path: " << s.mostProfitablePath(edges, bob, amount);
}