
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int n, m;
int rooms;

int dfs(int i, int j, vector<vector<int>> &castle, vector<vector<bool>> &vis, vector<vector<int>> &comps)
{
    if (vis[i][j])
        return 0;
    vis[i][j] = true;
    comps[i][j] = rooms;
    int sz = 1;

    if ((castle[i][j] & 2) == 0)
    {
        if ((i - 1) >= 0)
            sz += dfs(i - 1, j, castle, vis, comps);
    }

    if ((castle[i][j] & 4) == 0)
    {
        if ((j + 1) < m)
            sz += dfs(i, j + 1, castle, vis, comps);
    }

    if ((castle[i][j] & 8) == 0)
    {
        if ((i + 1) < n)
            sz += dfs(i + 1, j, castle, vis, comps);
    }

    if ((castle[i][j] & 1) == 0)
    {
        if ((j - 1) >= 0)
            sz += dfs(i, j - 1, castle, vis, comps);
    }

    return sz;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    cin >> m >> n;
    rooms = 0;

    vector<vector<int>> castle(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> castle[i][j];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> comps(n, vector<int>(m, -1));
    map<int, int> rank;

    int max_size = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                int size = dfs(i, j, castle, vis, comps);
                rank[rooms] = size;
                max_size = max(max_size, size);
                rooms++;
            }
        }
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //     {
    //         cout << comps[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for(auto pair : rank) {
    //     cout << pair.first << " " << pair.second << "\n";
    // }

    int max_size_remove = max_size;
    int ri = n;
    int ci = 1;
    char d = 'E';

    for (int j = 0; j < m; j++)
    {
        for (int i = (n - 1); i >= 0; i--)
        {
            int cc = comps[i][j];
            int cn = comps[i][j];
            int ce = comps[i][j];
            if ((i - 1) >= 0)
            {
                cn = comps[i - 1][j];
                if (cn != cc)
                {
                    int sze = rank[cn] + rank[cc];
                    if (sze > max_size_remove)
                    {
                        max_size_remove = sze;
                        ri = i + 1;
                        ci = j + 1;
                        d = 'N';
                        // cout << "inside n\n";
                        // cout << cc << " " << cn << " " << ce << " " << i + 1 << " " << j + 1 << "\n";
                    }
                }
            }

            if ((j + 1) < m)
            {
                ce = comps[i][j + 1];
                if (ce != cc)
                {
                    int sze = rank[ce] + rank[cc];
                    if (sze > max_size_remove)
                    {
                        max_size_remove = sze;
                        ri = i + 1;
                        ci = j + 1;
                        d = 'E';
                        // cout << "inside e\n";
                        // cout << cc << " " << cn << " " << ce << " " << i + 1 << " " << j + 1 << "\n";
                    }
                }
            }
        }
    }

    cout << rooms << "\n";
    cout << max_size << "\n";
    cout << max_size_remove << "\n";
    cout << ri << " " << ci << " " << d << "\n";
}