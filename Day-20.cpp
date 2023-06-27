Question-- > floor in bst int floorInBST(TreeNode<int> *root, int X)
{
    int floor = -1;
    while (root)
    {
        if (root->val == X)
            return X;
        else if (root->val < X)
        {
            floor = root->val;
            root = root->right;
        }
        else
            root = root->left;
    }
    return floor;
}

Question-- > finde ceil in bst int findCeil(BinaryTreeNode<int> *root, int X)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == X)
            return X;
        else if (root->data > X)
        {
            ceil = root->data;
            root = root->left;
        }
        else
            root = root->right;
    }
    return ceil;
}

Question--->kth largest int KthLargestNumber(TreeNode<int> *root, int k)
{
    // Write your code here.
    stack<TreeNode<int> *> st;
    if (!root)
        return -1;
    TreeNode<int> *temp = root;
    int count = 0;
    while (temp != NULL || !st.empty())
    {
        if (temp)
        {
            st.push(temp);
            temp = temp->right;
        }
        else
        {
            count++;
            if (count == k)
                return st.top()->data;
            temp = st.top()->left;
            st.pop();
        }
    }
    return -1;
}

Question-- > kth smallest bst int kthSmallest(TreeNode<int> *root, int k)
{
    //	Write the code here.
    stack<TreeNode<int> *> st;
    if (!root)
        return -1;
    TreeNode<int> *temp = root;
    while (temp != NULL || !st.empty())
    {
        if (temp)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            k--;
            if (k == 0)
                return st.top()->data;
            temp = st.top()->right;
            st.pop();
        }
    }
    return -1;
}

Question-- > bst iterator class BSTIterator
{
    stack<BinaryTreeNode<int> *> st;
    bool reverse;
    void pushAll(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return;
        while (node)
        {
            st.push(node);
            if (reverse == false)
                node = node->left;
            else
                node = node->right;
        }
    }

public:
    BSTIterator(BinaryTreeNode<int> *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        BinaryTreeNode<int> *temp = st.top();
        st.pop();
        if (!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if (!root)
        return 0;
    BinaryTreeNode<int> *node = root;
    BSTIterator l(root, false);
    BSTIterator r(node, true);

    int i = l.next();
    int j = r.next();
    while (i < j)
    {
        if (i + j == k)
            return true;
        if (i + j < k)
            i = l.next();
        else
            j = r.next();
    }
    return false;
}

Question-- > bst iterator class BSTiterator
{
    stack<TreeNode<int> *> st;
    void pushAll(TreeNode<int> *node)
    {
        if (node == NULL)
            return;
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int> *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
};

Question-- > serialize and deserialize
                 string
                 serializeTree(TreeNode<int> *root)
{
    if (root == NULL)
        return "";
    string ans = "";
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            ans.append(to_string(temp->data) + ",");
            q.push(temp->left);
            q.push(temp->right);
        }
        else
            ans.append("#,");
    }
    return ans;
}

TreeNode<int> *deserializeTree(string &data)
{
    if (data.empty())
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');

    TreeNode<int> *root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *cur = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
            cur->left = NULL;
        else
        {
            cur->left = new TreeNode<int>(stoi(str));
            q.push(cur->left);
        }
        getline(s, str, ',');

        if (str == "#")
            cur->right = NULL;
        else
        {
            cur->right = new TreeNode<int>(stoi(str));
            q.push(cur->right);
        }
    }
    return root;
}

Question--->flatten a binary tree void flatten(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&pre, BinaryTreeNode<int> *&head)
{
    if (root == NULL)
        return;
    flatten(root->left, pre, head);
    if (pre == NULL)
        head = root;
    else
    {
        pre->right = root;
        root->left = head;
    }
    pre = root;
    flatten(root->right, pre, head);
}
BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *temp = NULL, *head = NULL;
    flatten(root, temp, head);
    return head;
}

Question--->kth largest element in bt class Kthlargest
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int largest;

public:
    Kthlargest(int k, vector<int> &nums)
    {
        largest = k;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            while (pq.size() > k)
                pq.pop();
        }
    }

    void add(int num)
    {
        pq.push(num);
        if (pq.size() > largest)
            pq.pop();
        //  return pq.top();
    }

    int getKthLargest()
    {
        return pq.top();
    }
};

// Question --->kth largest in array
#include <bits/stdc++.h>
int kthLargest(vector<int> &nums, int size, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
        while (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

QUestion-- > count distinct element in
#include <bits/stdc++.h>
                 vector<int>
                 countDistinctElements(vector<int> &A, int k)
{
    int j = 0, i = 0, n = A.size();
    unordered_map<int, int> mp;
    vector<int> v;
    while (j < n)
    {
        mp[A[j]]++;
        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            v.push_back(mp.size());
            if (mp.find(A[i]) != mp.end())
            {
                mp[A[i]]--;
                if (mp[A[i]] == 0)
                    mp.erase(A[i]);
            }
            i++;
            j++;
        }
    }
    return v;
}

// flood fill algorithm
void dfs(vector<vector<int>> &ans, int sr, int sc, int color, int old_color, int drow[], int dcol[], vector<vector<int>> &vis)
{
    int n = ans.size();
    int m = ans[0].size();
    vis[sr][sc] = 1;
    ans[sr][sc] = color;
    for (int i = 0; i < 4; i++)
    {
        int nrow = sr + drow[i];
        int ncol = sc + dcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && ans[nrow][ncol] == old_color)
        {
            dfs(ans, nrow, ncol, color, old_color, drow, dcol, vis);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> ans = image;
    int old_color = image[sr][sc];
    int n = ans.size();
    int m = ans[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, -1, 0, +1};
    dfs(ans, sr, sc, color, old_color, drow, dcol, vis);
    return ans;
}