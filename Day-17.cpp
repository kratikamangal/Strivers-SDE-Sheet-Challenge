// Question-- > Nth root of element int func(int mid, int n, int m)
// {
//     long long ans = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         ans = ans * mid;
//         if (ans > m)
//             return 2;
//     }
//     if (ans == m)
//         return 0;
//     return 1;
// }
// int NthRoot(int n, int m)
// {

//     int low = 1, high = m;
//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         int ansN = func(mid, n, m);
//         if (ansN == 2)
//         {
//             high = mid - 1;
//         }
//         else if (ansN == 1)
//             low = mid + 1;
//         else if (ansN == 0)
//             return mid;
//     }
//     return -1;
// }

// // level order traversal
// #include <bits/stdc++.h>
// /************************************************************

//     Following is the BinaryTreeNode class structure

//     template <typename T>
//     class BinaryTreeNode {
//        public:
//         T val;
//         BinaryTreeNode<T> *left;
//         BinaryTreeNode<T> *right;

//         BinaryTreeNode(T val) {
//             this->val = val;
//             left = NULL;
//             right = NULL;
//         }
//     };

// ************************************************************/
// vector<int> getLevelOrder(BinaryTreeNode<int> *root)
// {
//     vector<int> ans;
//     if (!root)
//         return ans;
//     queue<BinaryTreeNode<int> *> q;
//     q.push(root);
//     ans.push_back({root->val});
//     while (!q.empty())
//     {
//         int size = q.size();
//         vector<int> temp;
//         for (int i = 0; i < size; i++)
//         {
//             BinaryTreeNode<int> *p = q.front();
//             q.pop();
//             if (p->left)
//             {
//                 ans.push_back(p->left->val);
//                 q.push(p->left);
//             }
//             if (p->right)
//             {
//                 ans.push_back(p->right->val);
//                 q.push(p->right);
//             }
//         }
//         // if(!temp.empty())
//         // ans.push_back(temp);
//     }
//     return ans;
// }

// Question-- > diameter of binary tree int height(TreeNode<int> *root, int &dia)
// {
//     if (root == NULL)
//         return 0;
//     int lh = height(root->left, dia);
//     int rh = height(root->right, dia);
//     dia = max(dia, lh + rh);
//     return 1 + max(lh, rh);
// }
// int diameterOfBinaryTree(TreeNode<int> *root)
// {
//     // Write Your Code Here.
//     int dia = 0;
//     height(root, dia);
//     return dia;
// }

// Question-- > balanced or not int height(BinaryTreeNode<int> * root)
// {
//     if (root == NULL)
//         return 0;
//     int lh = height(root->left);
//     if (lh == -1)
//         return -1;
//     int rh = height(root->right);
//     if (rh == -1)
//         return -1;
//     if (abs(lh - rh) > 1)
//         return -1;
//     return 1 + max(lh, rh);
// }
// bool isBalancedBT(BinaryTreeNode<int> *root)
// {
//     // Write your code here.
//     if (height(root) == -1)
//         return 0;
//     return 1;
// }

// // lca
// TreeNode<int> *lca(TreeNode<int> *root, int x, int y)
// {
//     if (root == NULL || root->data == x || root->data == y)
//         return root;
//     TreeNode<int> *left = lca(root->left, x, y);
//     TreeNode<int> *right = lca(root->right, x, y);
//     if (left == NULL)
//         return right;
//     else if (!right)
//         return left;
//     else
//         return root;
// }
// int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
// {
//     if (root == NULL)
//         return -1;
//     TreeNode<int> *n = lca(root, x, y);
//     return n->data;
// }

// // is identical or not

// bool identicalTrees(BinaryTreeNode<int> *r1, BinaryTreeNode<int> *r2)
// {
//     if (r1 == NULL || r2 == NULL)
//         return r1 == r2;
//     return r1->data == r2->data && identicalTrees(r1->left, r2->left) && identicalTrees(r1->right, r2->right);
// }

// // zig zag traversal
// vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
// {
//     vector<int> ans;
//     if (root == NULL)
//         return ans;
//     int flag = 0;
//     queue<BinaryTreeNode<int> *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         int size = q.size();
//         vector<int> temp(size);
//         for (int i = 0; i < size; i++)
//         {
//             BinaryTreeNode<int> *node = q.front();
//             q.pop();
//             int s = flag == 0 ? i : size - i - 1;
//             temp[s] = node->data;
//             if (node->left)
//                 q.push(node->left);
//             if (node->right)
//                 q.push(node->right);
//         }
//         flag = !flag;
//         for (auto it : temp)
//             ans.push_back(it);
//     }
//     return ans;
// }

// // Question -->boundary traversal
// #include <bits/stdc++.h>
// /************************************************************

//     Following is the Binary Tree node structure:

//     template <typename T>
//     class TreeNode {
//         public :
//         T data;
//         TreeNode<T> *left;
//         TreeNode<T> *right;

//         TreeNode(T data) {
//             this -> data = data;
//             left = NULL;
//             right = NULL;
//         }

//         ~TreeNode() {
//             if(left)
//                 delete left;
//             if(right)
//                 delete right;
//         }
//     };

// ************************************************************/
//  bool isLeaf(TreeNode<int> *root)
//     {
//         if(root!=NULL && root->left==NULL && root->right==NULL)
//         return true;
//         return false;
//     }
//     void LeftBoundary(TreeNode<int> *cur,vector<int>&ans)
//     {

//         TreeNode<int> *root=cur;
//         if(root==NULL)
//         return;
//         while(root)
//         {
//             if(!isLeaf(root))
//             ans.push_back(root->data);
//             if(root->left)
//             root=root->left;
//             else
//             root=root->right;
//         }
//     }
//     void RightBoundary(TreeNode<int> *cur,vector<int>&ans)
//     {
//          TreeNode<int> *root=cur;
//         vector<int>temp;
//         while(root)
//         {
//            if(!isLeaf(root))
//             temp.push_back(root->data);
//             if(root->right)
//             root=root->right;
//             else
//             root=root->left;
//         }
//         for(int i=temp.size()-1;i>=0;i--)
//         ans.push_back(temp[i]);
//     }
//     void LeafNodes(TreeNode<int> *root,vector<int>&ans)
//     {
//         if(root==NULL)
//         return;
//         if(isLeaf(root))
//         ans.push_back(root->data);
//         LeafNodes(root->left,ans);
//         LeafNodes(root->right,ans);
//     }
// vector<int> traverseBoundary(TreeNode<int>* root){
//      vector<int>ans;
//         if(root==NULL)
//         return ans;
//         if(isLeaf(root))
//         {
//             ans.push_back(root->data);
//             return ans;
//         }
//         ans.push_back(root->data);
//         TreeNode<int> *node=root;
//         LeftBoundary(root->left,ans);
//         LeafNodes(node,ans);
//         // cout<<root->right->data<<"    ";
//         RightBoundary(root->right,ans);
//         return ans;
// }