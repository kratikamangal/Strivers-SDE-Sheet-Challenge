Question-- > populating nodes at same level void connectNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    queue<BinaryTreeNode<int> *> q;
    if (root == NULL)
        return;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        BinaryTreeNode<int> *prev = q.front();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *n = q.front();
            q.pop();
            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
                q.push(n->right);
            if (i + 1 == size && prev != n)
            {
                prev->next = n;
                prev = prev->next;
                prev->next = NULL;
            }
            else if (prev != n)
            {
                prev->next = n;
                prev = prev->next;
            }
            else if (i + 1 == size)
                prev->next = NULL;
        }
    }
}

Question-- > search in bst bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    while (root)
    {
        if (root->data == x)
            return true;
        else if (root->data > x)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

Question--->construct tree from preorder traversal
    TreeNode<int> *
    tree(vector<int> &pre, int size, int &i, int upper_b)
{
    if (i >= size || pre[i] > upper_b)
        return NULL;
    TreeNode<int> *root = new TreeNode<int>(pre[i++]);
    root->left = tree(pre, size, i, root->data);
    root->right = tree(pre, size, i, upper_b);
    return root;
}
TreeNode<int> *preOrderTree(vector<int> &preorder)
{
    int i = 0;
    return tree(preorder, preorder.size(), i, INT_MAX);
}

Question-- > validate bst bool isValidBST(BinaryTreeNode<int> *root, double mini, double maxi)
{
    if (root == NULL)
        return true;
    if (root->data > maxi || root->data < mini)
        return false;
    return isValidBST(root->left, mini, root->data) && isValidBST(root->right, root->data, maxi);
}
bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    return isValidBST(root, -2e31, 2e31);
}

Question-- > lca in bst
                 TreeNode<int> *
                 LCAinaBST(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    // Write your code here
    if (root == NULL)
        return root;
    if (root->data < p->data && root->data < q->data)
        return LCAinaBST(root->right, p, q);
    if (root->data > p->data && root->data > q->data)
        return LCAinaBST(root->left, p, q);
    return root;
}

Question-- > predecessor and successor
                 pair<int, int>
                 predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // Write your code here.
    BinaryTreeNode<int> *pre, *suc;
    if (root == NULL)
    {
        pre = NULL;
        suc = NULL;
        return {-1, -1};
    }
    BinaryTreeNode<int> *cur = root;
    pre = NULL, suc = NULL;
    while (root)
    {
        if (root->data > key)
        {
            suc = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    while (cur)
    {
        if (cur->data >= key)
        {
            cur = cur->left;
        }
        else
        {
            pre = cur;
            cur = cur->right;
        }
    }
    int x = -1, y = -1;
    if (pre != NULL)
        x = pre->data;
    if (suc != NULL)
        y = suc->data;
    return {x, y};
}

// create bst from sorted array
TreeNode<int> *solve(vector<int> &arr, int low, int high)
{
    if (high < low)
        return NULL;
    int mid = (low + high) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = solve(arr, low, mid - 1);
    root->right = solve(arr, mid + 1, high);
    return root;
}
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    return solve(arr, 0, n - 1);
}