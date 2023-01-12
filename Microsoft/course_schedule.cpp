#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> adj[numCourses];

        for (auto i : prerequisites)
        {

            adj[i[0]].push_back(i[1]);
        }

        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto j : adj[i])
            {
                indegree[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            ans.push_back(front);
            for (auto neighbour : adj[front])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        if (ans.size() == numCourses)
            return true;

        return false;
    }
};
int main()
{
    vector<vector<int>> nums = {{1, 0}, {0, 1}};
    int n = 2;
    Solution s;
    cout << boolalpha;
    cout << "Possible: " << s.canFinish(n, nums);
}