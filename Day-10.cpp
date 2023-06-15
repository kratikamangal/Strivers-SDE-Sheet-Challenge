// Question -->Print permuatation
// #include <bits/stdc++.h>
 
//     void solve2(int index,string &s,vector<string>&ans)
//     {
//         if(index==s.size())
//         {
//             ans.push_back(s);
//             return;
//         }
//         for(int i=index;i<s.size();i++)
//         {
//             swap(s[index],s[i]);
//             solve2(index+1,s,ans);
//             swap(s[index],s[i]);
//         }

//     } 
// vector<string> findPermutations(string &s) {
//     vector<string>ans;
//         // string ds
//         solve2(0,s,ans);
//         return ans;
// }

// Question ---->N quuens
// void board(int n,int col,vector<vector<int>>&ans,vector<vector<int>>&s,vector<int>&left,vector<int>&lowerd,vector<int>&upperd)
//     {
//         if(col==n)
//         {
//             vector<int>temp;
//             for(int i=0;i<n;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 temp.push_back(s[i][j]);
//             }
//             ans.push_back(temp);
//             return;
//         }
//         for(int row=0;row<n;row++)
//         {
//             if(left[row]==0 && lowerd[row+col]==0 && upperd[n-1+col-row]==0)
//             {
//                 s[row][col]=1;
//                 left[row]=1;
//                 lowerd[col+row]=1;
//                 upperd[n-1+col-row]=1;
//                 board(n,col+1,ans,s,left,lowerd,upperd);
//                 s[row][col]=0;
//                 left[row]=0;
//                 lowerd[col+row]=0;
//                 upperd[n-1+col-row]=0;
//             }
//         }
//     }
// vector<vector<int>> solveNQueens(int n) {
//     vector<vector<int>>ans;
//         vector<vector<int>>s(n);
//         vector<int>a(n,0);
//         for(int i=0;i<n;i++)
//         s[i]=a;
//         vector<int>left(n,0);
//         vector<int>lowerd(2*n-1,0);
//         vector<int>upperd(2*n-1,0);
//         board(n,0,ans,s,left,lowerd,upperd);
//         return ans;
// }

// Question -->Soduku solver
// bool isSafe(int row,int col,int c,int board[9][9])
//     {
//         for(int i=0;i<9;i++)
//         {
//             if(board[row][i]==c)
//             return false;
//             if(board[i][col]==c)
//             return false;
//             if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)]==c)
//             return false;
//         }
//         return true;
//     }
//  bool solve(int board[9][9])
//     {
//         for(int i=0;i<9;i++)
//         {
//             for(int j=0;j<9;j++)
//             {
//                 if(board[i][j]==0)
//                 {
//                     for(int c=1;c<=9;c++)
//                     {
//                         if(isSafe(i,j,c,board))
//                         {
//                             board[i][j]=c;
//                             if(solve(board))
//                             return true;
//                             board[i][j]='.';
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// bool isItSudoku(int matrix[9][9]) {
//     return solve(matrix);
// }

// Question --->M coloring problem
// #include <bits/stdc++.h> 
//  bool isSafe(int col,int node,vector<vector<int>>&graph,int n,vector<int>&color)
//     {
//         for(int k=0;k<n;k++)
//         {
//             if(k!=node && graph[k][node]==1 && color[k]==col)
//             return false;
//         }
//         return true;
//     }
//     bool f(int node,vector<vector<int>> &graph,int m,int n,vector<int>&color)
//     {
//         if(node==n)
//         return true;
//         for(int i=1;i<=m;i++)
//         {
//             if(isSafe(i,node,graph,n,color))
//             {
//                 color[node]=i;
//                 if(f(node+1,graph,m,n,color))
//                 return true;
//                 color[node]=0;
//             }
//         }
//         return false;
        
//     }
// string graphColoring(vector<vector<int>> &graph, int m) {
//     int n=graph.size();
//     vector<int>color(n,0);
//         if(f(0,graph,m,n,color))
//         return "YES";
//         return "NO";
// }

// //Rat in a maze
// #include <bits/stdc++.h> 
// void solve(int row,int col,int n,vector<vector<int>>&m,vector<vector<int>>&ans,vector<int> &s,vector<vector<int>>&vis)
//     {
//         if(row==n-1 && col==n-1)
//         {
//           vis[row][col]=1;
//           vector<int>temp;
//             for(int i=0;i<n;i++)
//             {
//               for(int j=0;j<n;j++)
//               {
//                 temp.push_back(vis[i][j]);
//               }
//             }
//             ans.push_back(temp);
//             vis[row][col]=0;
//             return;
//         }
//         int delRow[]={-1,0,0,+1};
//         int delCol[]={0,-1,+1,0};
//         string dir="ULRD";
//         for(int i=0;i<4;i++)
//         {
//             int nrow=row+delRow[i];
//             int ncol=col+delCol[i];
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && m[nrow][ncol]==1)
//             {
//                 // s.push_back(1);
//                 vis[row][col]=1;
//                 solve(nrow,ncol,n,m,ans,s,vis);
//                 vis[row][col]=0;
//                 // s.pop_back();
//             }
//         }
//     }
// vector<vector<int> > ratInAMaze(vector<vector<int> > &m, int n){
//   vector<vector<int>>ans;
//         vector<vector<int>>vis(n,vector<int>(n,0));
//         vis[0][0]=1;
//         vector<int>s;
//         s.push_back(1);
//         if(m[0][0]==1)solve(0,0,n,m,ans,s,vis);
//         return ans;
// }

