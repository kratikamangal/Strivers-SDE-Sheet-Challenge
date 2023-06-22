// inorder traversal
void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    inorder(root, ans);
    return ans;
}

// preorder traversal
#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void preorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    preorder(root, ans);
    return ans;
}

// postorder traversal
void postorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    postorder(root, ans);
    return ans;
}
// left view
void left(TreeNode<int> *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    left(root->left, level + 1, ans);
    left(root->right, level + 1, ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    set<int> mp;
    left(root, 0, ans);
    return ans;
}

// bottom view
vector<int> bottomView(BinaryTreeNode<int> *root)
{

    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        BinaryTreeNode<int> *node = q.front().first;
        int ver = q.front().second;
        q.pop();
        mp[ver] = node->data;
        if (node->left)
            q.push({node->left, ver - 1});
        if (node->right)
            q.push({node->right, ver + 1});
    }
    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}

// get top view
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode<int> *node = q.front().first;
        int ver = q.front().second;
        q.pop();
        if (mp.find(ver) == mp.end())
            mp[ver] = node->val;
        if (node->left)
            q.push({node->left, ver - 1});
        if (node->right)
            q.push({node->right, ver + 1});
    }
    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}

// preorder ,postorder,inorder in single traversal
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    stack<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 1});
    vector<int> in, pre, post;
    while (!q.empty())
    {
        BinaryTreeNode<int> *node = q.top().first;
        int x = q.top().second;
        q.pop();
        if (x == 1)
        {
            pre.push_back(node->data);
            q.push({node, x + 1});
            if (node->left)
                q.push({node->left, 1});
        }
        else if (x == 2)
        {
            in.push_back(node->data);
            q.push({node, x + 1});
            if (node->right)
                q.push({node->right, 1});
        }
        else
        {
            post.push_back(node->data);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}

// vertical order traversal
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    if (root == NULL)
        return {};
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    map<int, map<int, vector<int>>> mp;

    while (!q.empty())
    {
        TreeNode<int> *node = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        mp[y][x].push_back(node->data);
        if (node->left)
        {
            q.push({node->left, {x + 1, y - 1}});
        }
        if (node->right)
        {
            q.push({node->right, {x + 1, y + 1}});
        }
    }
    vector<int> ans;
    for (auto it : mp)
    {
        vector<int> col;
        for (auto q : it.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        for (auto p : col)
            ans.push_back(p);
    }
    return ans;
}

// maximum width a bt
#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    int width = 0;
    while (!q.empty())
    {
        int size = q.size();
        int mini = q.front().second;
        int left, right;
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *node = q.front().first;
            long long j = q.front().second;
            q.pop();
            count++;
            if (node->left)
            {
                q.push({node->left, 1});
            }
            if (node->right)
            {
                q.push({node->right, 1});
            }
        }
        width = max(width, count);
    }
    return width;
}

// root to node path
bool getpath(TreeNode<int> *root, int x, vector<int> &ans)
{
    if (root == NULL)
        return false;
    ans.push_back(root->data);
    if (root->data == x)
    {
        // ans.push_back(x);
        return true;
    }

    if (getpath(root->left, x, ans) || getpath(root->right, x, ans))
        return true;
    ans.pop_back();
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    getpath(root, x, ans);
    return ans;
}
