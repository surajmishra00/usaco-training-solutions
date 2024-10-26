

#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> ans;
int n;
vector<vector<pair<int, int>>> graph(101);
vector<bool> graph_node(101, false);
vector<int> op(101);
vector<bool> vis(101);

void dfs2(int node)
{
    if (vis[node])
        return;
    vis[node] = true;

    for (auto nbr : graph[node])
    {
        if (vis[nbr.first])
            continue;

        op[nbr.first] = min(100, op[nbr.first] + nbr.second);
    }

    for (auto nbr : graph[node])
    {
        if (vis[nbr.first])
            continue;
        if (op[nbr.first] >= 50)
            dfs2(nbr.first);
    }
}

void dfs(int start)
{

    fill(op.begin(), op.end(), 0);
    fill(vis.begin(), vis.end(), false);
    // cout << "inside dfs: " << start << "\n";
    // for(int i = 1; i <= n; i++) cout << op[i] << " ";
    // cout << "\n";
    // for(int i = 1; i <= n; i++) cout << vis[i] << " ";
    // cout << "\n";

    op[start] = 100;

    dfs2(start);
    // for(int i = 1; i <= n; i++) cout << op[i] << " ";
    // cout << "\n";
    for (int i = 1; i < 101; i++)
    {
        if (graph_node[i] && i != start && op[i] >= 50 && vis[i])
            ans.push_back({start, i});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int c1, c2, per;
        cin >> c1 >> c2 >> per;
        graph_node[c1] = true;
        graph_node[c2] = true;
        graph[c1].push_back({c2, per});
    }

    // for (int i = 1; i < 101; i++)
    // {
    //     cout << i << ": \n";
    //     for (auto nbr : graph[i])
    //     {
    //         cout << nbr.first << " " << nbr.second << "\n";
    //     }
    // }

    for (int start = 1; start < 101; start++)
    {
        if (graph_node[start])
        {
            // cout << start << " ";
            dfs(start);
        }
    }

    sort(ans.begin(), ans.end());
    for (auto &pair : ans)
    {
        cout << pair.first << " " << pair.second << "\n";
    }
}