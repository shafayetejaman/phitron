#include <bits/stdc++.h>

using namespace std;

int main()
{


    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

    }
};

void print(TreeNode *ptr, vector<int> &ans)
{
    if (ptr == nullptr)
    {
        return;
    }
    print(ptr->left, ans);
    print(ptr->right, ans);
    ans.push_back(ptr->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here
    vector<int> ans;
    print(root, ans);
    return ans;
}

