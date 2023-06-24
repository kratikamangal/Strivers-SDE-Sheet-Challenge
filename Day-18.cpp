// Question-- > maximum path sum long long int maximumsum(TreeNode<int> *root, long long int &maxi)
// {
//     if (root == NULL)
//         return 0;
//     long long int ls = maximumsum(root->left, maxi);
//     long long int rs = maximumsum(root->right, maxi);
//     maxi = max(maxi, (long long int)root->val + ls + rs);
//     return (long long int)root->val + max(ls, rs);
// }
// long long int findMaxSumPath(TreeNode<int> *root)
// {
//     // Write your code here.
//     if (root == NULL || root->left == NULL || !root->right)
//         return -1;
//     long long int maxi = INT_MIN;
//     maximumsum(root, maxi);
//     return maxi;
// }

// Question-- > Construct binary tree from inorder and preorder
//                  TreeNode<int> *
//                  buildTreePre(unordered_map<int, int> &mp, vector<int> &in, int is, int ie, vector<int> &pre, int ps, int pe)
// {
//     if (ps > pe || is > ie)
//         return NULL;
//     TreeNode<int> *root = new TreeNode<int>(pre[ps]);
//     int inRoot = mp[root->data];
//     int numLeft = inRoot - is;

//     root->left = buildTreePre(mp, in, is, inRoot - 1, pre, ps + 1, ps + numLeft);
//     root->right = buildTreePre(mp, in, inRoot + 1, ie, pre, ps + numLeft + 1, pe);
//     return root;
// }
// TreeNode<int> *buildBinaryTree(vector<int> &in, vector<int> &pre)
// {
//     //    Write your code here
//     if (in.size() != pre.size())
//         return NULL;
//     int n = in.size();
//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++)
//         mp[in[i]] = i;
//     return buildTreePre(mp, in, 0, n - 1, pre, 0, n - 1);
// }

// Question-- > construct tree from postorder and inorder
// #include <bits/stdc++.h>
//                  TreeNode<int> *
//                  buildTree(vector<int> &in, int startin, int enin, vector<int> &post, int prein, int preend, unordered_map<int, int> &mp)
// {
//     if (startin > enin || prein > preend)
//         return NULL;
//     TreeNode<int> *root = new TreeNode<int>(post[preend]);
//     int inRoot = mp[root->data];
//     int numLeft = inRoot - startin;
//     root->left = buildTree(in, startin, inRoot - 1, post, prein, prein + numLeft - 1, mp);
//     root->right = buildTree(in, inRoot + 1, enin, post, prein + numLeft, preend - 1, mp);

//     return root;
// }
// TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postorder, vector<int> &inorder)
// {
//     if (inorder.size() != postorder.size())
//         return NULL;
//     unordered_map<int, int> mp;
//     for (int i = 0; i < inorder.size(); i++)
//         mp[inorder[i]] = i;
//     int n = inorder.size();
//     TreeNode<int> *root = buildTree(inorder, 0, n - 1, postorder, 0, n - 1, mp);
//     return root;
// }

// Question-- > check symmetric binary tree or not bool check(BinaryTreeNode<int> * r1, BinaryTreeNode<int> *r2)
// {
//     if (r1 == NULL || r2 == NULL)
//         return r1 == r2;

//     return (r1->data == r2->data) && check(r1->left, r2->right) && check(r1->right, r2->left);
// }

// bool isSymmetric(BinaryTreeNode<int> *root)
// {
//     // Write your code here.
//     if (root == NULL)
//         return true;
//     return check(root->left, root->right);
// }

// Question-- > flatten a binary tree
//                  TreeNode<int> *
//                  flattenBinaryTree(TreeNode<int> *root)
// {
//     // Write your code here.
//     if (root == NULL)
//         return root;
//     stack<TreeNode<int> *> st;
//     st.push(root);
//     while (!st.empty())
//     {
//         TreeNode<int> *cur = st.top();
//         st.pop();
//         if (cur->right)
//             st.push(cur->right);
//         if (cur->left)
//             st.push(cur->left);
//         if (!st.empty())
//             cur->right = st.top();
//         cur->left = NULL;
//     }
//     return root;
// }

// QUestion--->children sum property void changeTree(BinaryTreeNode<int> *root)
// {
//     // Write your code here.
//     if (root == NULL)
//         return;
//     int child = 0;
//     if (root->left)
//         child += root->left->data;
//     if (root->right)
//         child += root->right->data;
//     if (child >= root->data)
//         root->data = child;
//     else
//     {
//         if (root->left)
//             root->left->data = root->data;
//         if (root->right)
//             root->right->data = root->data;
//     }
//     changeTree(root->left);
//     changeTree(root->right);
//     int tat = 0;
//     if (root->left)
//         tat += root->left->data;
//     if (root->right)
//         tat += root->right->data;
//     if (tat >= root->data)
//         root->data = tat;
// }