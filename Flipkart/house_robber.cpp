#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
private:
    vector<int> getRes(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }
        vector<int> left = getRes(root->left);
        vector<int> right = getRes(root->right);
        vector<int> res;

        res.push_back(left[1] + right[1] + root->val);
        res.push_back(max(left[0], left[1]) + max(right[0], right[1]));

        return res;
    }

public:
    int rob(TreeNode *root)
    {
        vector<int> ans = getRes(root);
        int res = max(ans[0], ans[1]);
        return res;
    }
};
int main()
{
    TreeNode *head = new TreeNode(3, new TreeNode(2, NULL, new TreeNode(3)), new TreeNode(3, NULL, new TreeNode(1)));
    Solution s;
    cout << "Max amount of money the thief can rob: " << s.rob(head);
}