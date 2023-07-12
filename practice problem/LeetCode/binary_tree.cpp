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
template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if (root == nullptr)
    {
        return {};
    }
    vector<int> ans;
    queue<BinaryTreeNode<int> *> que;
    que.push(root);
    while (!que.empty())
    {
        BinaryTreeNode<int> *curr = que.front();
        que.pop();

        ans.push_back(curr->val);

        if (curr->left)
        {
            que.push(curr->left);
        }
        if (curr->right)
        {
            que.push(curr->right);
        }
    }
    return ans;
}
long long left_sum(BinaryTreeNode<int> *ptr)
{
    if (ptr == nullptr)
        return 0;
    long long sum = 0;
    if (ptr->left)
        sum = ptr->left->data;

    sum += left_sum(ptr->left);
    sum += left_sum(ptr->right);
    return sum;
}

long long leftSum(BinaryTreeNode<int> *root)
{
    return left_sum(root);
}