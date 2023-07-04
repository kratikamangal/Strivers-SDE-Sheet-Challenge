Question-- > dijikstra algorithm
#include <bits/stdc++.h>
                 vector<int>
                 dijkstra(vector<vector<int>> &vec, int V, int edges, int S)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    set<pair<int, int>> pq;
    pq.insert({0, S});
    while (!pq.empty())
    {
        auto p = *(pq.begin());
        int dis = p.first;
        int node = p.second;
        pq.erase(p);
        for (auto it : adj[node])
        {
            int d = it.second;
            int v = it.first;
            if (dis + d < dist[v])
            {
                if (dist[v] != 1e9)
                    pq.erase({dist[v], v});
                dist[v] = dis + d;
                pq.insert({dist[v], v});
            }
        }
    }
    return dist;
}

// bellman ford algorithm
#include <bits/stdc++.h>
int bellmonFord(int V, int m, int S, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(V + 1, 1e9);
    dist[S] = 0;
    for (int i = 1; i < V; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // for(auto it:edges)
    //     {
    //         int u=it[0];
    //         int v=it[1];
    //         int wt=it[2];
    //         if(dist[u]+wt<dist[v])
    //         {
    //            return {-1};
    //         }
    //     }
    return dist[dest];
}

// floyd warshall
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

    vector<vector<int>> matrix(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)
    {
        matrix[i][i] = 0;
    }
    for (auto it : edges)
    {
        int u = it[0] - 1, v = it[1] - 1, wt = it[2];
        matrix[u][v] = wt;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    return matrix[src - 1][dest - 1];
}

// mst prim
#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int V, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<int>> adj[V];
    for (int i = 0; i < m; i++)
    {

        int u = g[i].first.first - 1;

        int v = g[i].first.second - 1;

        int wt = g[i].second;

        adj[u].push_back({v, wt});

        adj[v].push_back({u, wt});
    }
    vector<int> vis(V, 0);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, -1}});
    vector<pair<pair<int, int>, int>> ans;
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();
        if (vis[node] == 1)
            continue;
        if (par != -1)
            ans.push_back({{node + 1, par + 1}, wt});
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it[0]] == 0)
            {
                pq.push({it[1], {it[0], node}});
            }
        }
    }
    return ans;
}

// maximum product subarray
#include <bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
    int pref = 1, suf = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pref == 0)
            pref = 1;
        if (suf == 0)
            suf = 1;
        pref = pref * arr[i];
        suf = suf * arr[n - 1 - i];
        maxi = max(maxi, max(pref, suf));
    }
    return maxi;
}

// kruskal algorithm mst
#include <bits/stdc++.h>
int findPar(int u, vector<int> &parent)
{
    if (parent[u] == u)
        return u;
    return parent[u] = findPar(parent[u], parent);
}
void Union_rank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = findPar(u, parent);
    int pv = findPar(v, parent);

    int ranku = rank[pu];
    int rankv = rank[pv];
    if (pu == pv)
        return;
    if (ranku > rankv)
    {
        parent[pv] = pu;
    }
    else if (ranku < rankv)
    {
        parent[pu] = pv;
    }
    else
    {
        parent[pu] = pv;
        rank[pv] += 1;
    }
}
void Union_size(int u, int v, vector<int> &parent, vector<int> &size)
{
    int pu = findPar(u, parent);
    int pv = findPar(v, parent);
    if (pu == pv)
        return;
    if (size[pu] > size[pv])
    {
        parent[pv] = pu;
        size[pu] += size[pv];
    }
    else
    {
        parent[pu] = pv;
        size[pv] += size[pu];
    }
}
int kruskalMST(int V, int m, vector<vector<int>> &graph)
{
    vector<int> parent(V + 1), rank(V + 1, 0), size(V + 1, 1);
    for (int i = 0; i < V + 1; i++)
        parent[i] = i;
    sort(graph.begin(), graph.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });
    int sum = 0;
    for (auto it : graph)
    {
        int wt = it[2];
        int u = it[0];
        int v = it[1];
        int pu = findPar(u, parent);
        int pv = findPar(v, parent);
        if (pu == pv)
            continue;
        Union_rank(u, v, parent, rank);
        sum += wt;
    }
    return sum;
}

// strongly connected component
#include <bits/stdc++.h>
void dfs(vector<int> adj[], int node, stack<int> &st, vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            dfs(adj, it, st, vis);
        }
    }
    st.push(node);
}
void dfs3(vector<int> adjT[], int node, vector<int> &vis, vector<int> &s)
{
    vis[node] = 1;
    s.push_back(node);
    for (auto it : adjT[node])
    {
        if (vis[it] == 0)
            dfs3(adjT, it, vis, s);
    }
}
vector<vector<int>> stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for (auto i : edges)
        adj[i[0]].push_back(i[1]);
    vector<int> vis(V, 0);
    vector<vector<int>> ans;
    stack<int> st;
    // vector<int>ad[V];
    // for(auto it:adj)
    // ad[it[0]].push_back(it[1]);

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
            dfs(adj, i, st, vis);
    }

    vector<int> adjT[V];

    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
            adjT[it].push_back(i);
    }
    int count = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        vector<int> temp;
        if (vis[node] == 0)
        {
            dfs3(adjT, node, vis, temp);
        }
        ans.push_back(temp);
    }
    return ans;
}