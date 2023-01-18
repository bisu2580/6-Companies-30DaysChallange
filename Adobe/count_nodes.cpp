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
    pair<int, int> getTree(TreeNode *root, int &ans)
    {

        if (root == NULL)
        {
            return {0, 0};
        }

        auto num1 = getTree(root->left, ans);
        auto num2 = getTree(root->right, ans);

        int sum = num1.first + num2.first + root->val;
        int den = num1.second + num2.second + 1;
        if (sum / den == root->val)
        {
            ans++;
        }
        return {sum, den};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {

        int ans = 0;
        getTree(root, ans);
        return ans;
    }
};
int main()
{

    TreeNode *t = new TreeNode(4, new TreeNode(8, new TreeNode(0, NULL, NULL), new TreeNode(1, NULL, NULL)), new TreeNode(5, NULL, new TreeNode(6, NULL, NULL)));
    Solution s;
    cout << s.averageOfSubtree(t);
}