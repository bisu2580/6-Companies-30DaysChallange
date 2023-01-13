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
    void traverse(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        traverse(root->left, ans);
        ans.push_back(root->val);
        traverse(root->right, ans);
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> ans;

        traverse(root1, ans);

        traverse(root2, ans);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
int main()
{
    TreeNode *root1 = new TreeNode(2, new TreeNode(1), new TreeNode(4));
    TreeNode *root2 = new TreeNode(1, new TreeNode(0), new TreeNode(3));
    Solution s;
    vector<int> ans = s.getAllElements(root1, root2);
    cout << "Sorted list: ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
}