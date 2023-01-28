#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int calculate(vector<vector<int>> &students, vector<vector<int>> &mentors, int sIndex, int mIndex)
    {
        int score = 0;
        for (int i = 0; i < students[sIndex].size(); i++)
        {
            if (students[sIndex][i] == mentors[mIndex][i])
            {
                score++;
            }
        }
        return score;
    }
    void answer(vector<vector<int>> &students, vector<vector<int>> &mentors, vector<bool> mentorsVisited, int index, int score, int &res)
    {
        int n = students.size();
        if (index >= n)
        {
            res = max(res, score);
            return;
        }
        int compatibleScore = 0;
        for (auto i = 0; i < n; i++)
        {
            if (!mentorsVisited[i])
            {
                mentorsVisited[i] = true;
                compatibleScore = calculate(students, mentors, index, i);
                answer(students, mentors, mentorsVisited, index + 1, score + compatibleScore, res);
                mentorsVisited[i] = false;
            }
        }
    }

public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int n = students.size();
        vector<bool> mentorsVisited(n, false);
        int index = 0, res = 0, score = 0;
        answer(students, mentors, mentorsVisited, index, score, res);
        return res;
    }
};
int main()
{
    vector<vector<int>> students = {{1, 1, 0}, {1, 0, 1}, {0, 0, 1}};
    vector<vector<int>> mentors = {{1, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    Solution s;
    cout << "Maximum compatibility score: " << s.maxCompatibilitySum(students, mentors);
}