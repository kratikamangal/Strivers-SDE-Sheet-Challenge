// Question-- > dfs void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
// {
//     vis[node] = 1;
//     ans.push_back(node);
//     for (auto it : adj[node])
//     {
//         if (vis[it] == 0)
//             dfs(it, adj, vis, ans);
//     }
// }
// vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
// {
//     vector<int> adj[V];
//     for (auto it : edges)
//     {
//         adj[it[0]].push_back(it[1]);
//         adj[it[1]].push_back(it[0]);
//     }
//     vector<int> vis(V, 0);
//     vector<vector<int>> res;
//     for (int i = 0; i < V; i++)
//     {
//         if (vis[i] == 0)
//         {
//             vector<int> ans;
//             dfs(i, adj, vis, ans);
//             res.push_back(ans);
//         }
//     }
//     return res;
// }

// // cycle detction in a graph
// int dfs(vector<int> adj[], vector<int> &vis, int node, int par)
// {
//     vis[node] = 1;
//     for (auto it : adj[node])
//     {
//         if (vis[it] == 0)
//         {
//             if (dfs(adj, vis, it, node) == 0)
//                 return 0;
//         }
//         else if (vis[it] != 0 && it != par)
//             return 0;
//     }
//     return 1;
// }
// string cycleDetection(vector<vector<int>> &edges, int n, int m)
// {
//     vector<int> adj[n + 1];
//     for (auto it : edges)
//     {
//         adj[it[1]].push_back(it[0]);
//         adj[it[0]].push_back(it[1]);
//     }

//     vector<int> vis(n + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         if (vis[i] == 0)
//         {
//             if (dfs(adj, vis, i, -1) == 0)
//                 return "Yes";
//         }
//     }
//     return "No";
// }

// // detect cycle in directed graph
// bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
// {
//     vis[node] = 1;
//     pathVis[node] = 1;
//     for (auto it : adj[node])
//     {
//         if (vis[it] == 0)
//         {
//             if (dfs(it, adj, vis, pathVis) == false)
//                 return false;
//         }
//         else if (pathVis[it] == 1)
//             return false;
//     }
//     pathVis[node] = 0;
//     return true;
// }
// int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
// {
//     vector<int> adj[n + 1];
//     for (auto it : edges)
//         adj[it.first].push_back(it.second);
//     vector<int> pathVis(n + 1, 0);
//     vector<int> vis(n + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         if (vis[i] == 0)
//         {

//             if (dfs(i, adj, vis, pathVis) == false)
//                 return true;
//         }
//     }
//     return false;
// }

// Question-- > topo sort
// #include <bits/stdc++.h>

//                  vector<int>
//                  topologicalSort(vector<vector<int>> &edges, int V, int e)
// {
//     queue<int> q;
//     vector<int> adj[V];
//     for (auto it : edges)
//         adj[it[0]].push_back(it[1]);
//     vector<int> ans, indegree(V);
//     for (int i = 0; i < V; i++)
//     {
//         for (auto it : adj[i])
//         {
//             indegree[it]++;
//         }
//     }
//     for (int i = 0; i < V; i++)
//     {
//         if (indegree[i] == 0)
//             q.push(i);
//     }
//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();
//         ans.push_back(node);
//         for (auto it : adj[node])
//         {

//             indegree[it]--;
//             if (indegree[it] == 0)
//                 q.push(it);
//         }
//     }
//     return ans;
// }

// Question-- > check bipartite bool dfs(int node, int col, vector<int> &color, vector<int> graph[])
// {
//     // if(color[node]==-1)

//     for (auto it : graph[node])
//     {
//         if (color[it] == -1)
//         {
//             color[it] = !color[node];
//             if (dfs(it, !col, color, graph) == false)
//                 return false;
//         }
//         else if (color[node] == color[it])
//             return false;
//     }
//     return true;
// }
// bool isGraphBirpatite(vector<vector<int>> &edges)
// {
//     int n = edges.size();
//     vector<int> graph[n];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (edges[i][j] == 1)
//             {
//                 graph[i].push_back(j);
//                 graph[j].push_back(i);
//             }
//         }
//     }
//     vector<int> color(n + 1, -1);
//     for (int i = 0; i < n; i++)
//     {
//         if (color[i] == -1)
//         {
//             color[i] = 0;
//             if (dfs(i, 0, color, graph) == false)
//                 return 0;
//         }
//     }
//     return 1;
// }

// number of island
//   void dfs(int row,int col,int** grid,vector<vector<int>>& vis,int d[],int n,int m)
//      {

//         vis[row][col]=1;
//         for(int i=0;i<3;i++)
//         {
//            for(int j=0;j<3;j++)
//            {
//                int nrow=row+d[i];
//             int ncol=col+d[j];
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
//             {
//                  dfs(nrow,ncol,grid,vis,d,n,m);
//             }
//            }
//         }

//     }
// int getTotalIslands(int** grid, int n, int m)
// {

//         vector<vector<int>>vis(n,vector<int>(m,0));
//         int d[]={-1,0,+1};
//         int count=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j]==1 && vis[i][j]==0)
//                 {
//                     count++;
//                     dfs(i,j,grid,vis,d,n,m);
//                 }
//             }
//         }
//         return count;
// }
