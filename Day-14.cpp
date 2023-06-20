Question-- > next smaller element
#include <bits/stdc++.h>
                 vector<int>
                 nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        else
            ans[i] = -1;
        st.push(arr[i]);
    }
    return ans;
}

Rotten oranges
#include <bits/stdc++.h>
    int
    minTimeToRot(vector<vector<int>> &grid, int n, int m)
{

    vector<vector<int>> mat = grid;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 2)
            {
                q.push({0, {i, j}});
                vis[i][j] = 1;
            }
        }
    }
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, -1, 0, +1};
    int time = 0;
    while (!q.empty())
    {
        int row = q.front().second.first;
        int col = q.front().second.second;
        int t = q.front().first;
        vis[row][col] = 1;
        q.pop();
        time = max(time, t);
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                grid[nrow][ncol] = 2;
                q.push({t + 1, {nrow, ncol}});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return time;
}

Maximum sliding window of size k
#include <bits/stdc++.h>
    vector<int>
    slidingWindowMaximum(vector<int> &arr, int &k)
{
    vector<int> ans;
    deque<int> q;
    int i = 0, j = 0;
    int n = arr.size();
    while (j < n)
    {
        while (!q.empty() && arr[q.back()] < arr[j])
            q.pop_back();
        q.push_back(j);
        if (j - i + 1 >= k)
        {
            ans.push_back(arr[q.front()]);
            if (q.front() == i)
                q.pop_front();
            i++;
        }
        j++;
    }
    return ans;
}

Question-- > stock span
                 vector<int>
                     ans(n);
stack<pair<int, int>> st;
for (int i = 0; i < n; i++)
{
    while (!st.empty() && st.top().first <= price[i])
        st.pop();
    if (!st.empty())
        ans[i] = abs(st.top().second - i);
    else
        ans[i] = i + 1;
    st.push({price[i], i});
}
return ans;
}

// Question --->largest reactangle
#include <bits/stdc++.h>
int largestRectangle(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<long long> nsr(n), nsl(n);
    stack<pair<long long, long long>> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            nsl[i] = -1;
        else
            nsl[i] = st.top().second;
        st.push({arr[i], i});
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            nsr[i] = n;
        else
            nsr[i] = st.top().second;
        st.push({arr[i], i});
    }
    long long maxA = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        long long width = nsr[i] - nsl[i] - 1;
        maxA = max(maxA, arr[i] * width);
    }
    return maxA;
}

// QUestion --> Celebrity problem
#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
        while (st.size() >= 2)
        {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            if (M[x][y] == 1)
                st.push(y);
            else
                st.push(x);
        }
    }
    int x;
    if (!st.empty())
    {
        x = st.top();
        for (int i = 0; i < n; i++)
        {
            if (x != i && M[i][x] == 0 || M[x][i] == 1)
                return -1;
        }
    }
    return x;
}

// power set
#include <bits/stdc++.h>
void solve(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    if (nums.size() == index)
    {
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[index]);
    solve(index + 1, nums, ds, ans);
    ds.pop_back();
    solve(index + 1, nums, ds, ans);
}
vector<vector<int>> pwset(vector<int> nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, nums, ds, ans);
    return ans;
}