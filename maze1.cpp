

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <deque>

using namespace std;
int w, h;
const int INF = (int)1e8;

vector<vector<int>> bfs(int si, int sj, vector<string> &grid)
{

    vector<vector<int>> dist(2 * h + 1, vector<int>(2 * w + 1, INF));
    vector<vector<bool>> vis(2 * h + 1, vector<bool>(2 * w + 1, false));
    dist[si][sj] = 0;
    vis[si][sj] = true;
    deque<int> pi;
    deque<int> pj;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    pi.push_back(si);
    pj.push_back(sj);

    while (!pi.empty())
    {
        int ci = pi.front();
        int cj = pj.front();
        pi.pop_front();
        pj.pop_front();
        for (int k = 0; k < 4; k++)
        {
            int wi = ci + dx[k];
            int wj = cj + dy[k];
            if ((wi >= 0) && (wi <= (2 * h + 1)) && (wj >= 0) && (wj <= (2 * w + 1)) && grid[wi][wj] != ' ')
                continue;

            int ni = ci + 2 * dx[k];
            int nj = cj + 2 * dy[k];
            if ((ni >= 1) && (ni < (2 * h)) && (nj >= 1) && (nj < (2 * w)) && !vis[ni][nj])
            {
                dist[ni][nj] = dist[ci][cj] + 1;
                vis[ni][nj] = true;
                pi.push_back(ni);
                pj.push_back(nj);
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);

    cin >> w >> h;
    cin.ignore();
    vector<string> grid(2 * h + 1);
    for (int i = 0; i < (2 * h + 1); i++)
    {
        string cur;
        getline(cin, cur);
        if (cur.length() < (2 * w + 1))
        {
            cur.append(2 * w + 1 - cur.length(), ' ');
        }
        grid[i] = cur;
    }

    int e1i = -1, e1j = -1;
    int e2i = -1, e2j = -1;
    int cnt = 0;
    for (int i = 1; i <= (2 * h - 1); i += 2)
    {
        for (int j = 1; j <= (2 * w - 1); j += 2)
        {
            if ((i == 1) || (i == (2 * h - 1)) || (j == 1) || (j == (2 * w - 1)))
            {
                if (i == 1)
                {
                    if (grid[i - 1][j] == ' ')
                    {
                        if (cnt == 0)
                        {
                            e1i = i, e1j = j;
                            cnt++;
                        }
                        else if (cnt == 1)
                        {
                            e2i = i, e2j = j;
                            cnt++;
                        }
                    }
                    if (j == 1)
                    {
                        if (grid[i][j - 1] == ' ')
                        {
                            if (cnt == 0)
                            {
                                e1i = i, e1j = j;
                                cnt++;
                            }
                            else if (cnt == 1)
                            {
                                e2i = i, e2j = j;
                                cnt++;
                            }
                        }
                    }

                    if (j == (2 * w - 1))
                    {
                        if (grid[i][j + 1] == ' ')
                        {
                            if (cnt == 0)
                            {
                                e1i = i, e1j = j;
                                cnt++;
                            }
                            else if (cnt == 1)
                            {
                                e2i = i, e2j = j;
                                cnt++;
                            }
                        }
                    }
                }
                else if (i == (2 * h - 1))
                {
                    if (grid[i + 1][j] == ' ')
                    {
                        if (cnt == 0)
                        {
                            e1i = i, e1j = j;
                            cnt++;
                        }
                        else if (cnt == 1)
                        {
                            e2i = i, e2j = j;
                            cnt++;
                        }
                    }
                    if (j == 1)
                    {
                        if (grid[i][j - 1] == ' ')
                        {
                            if (cnt == 0)
                            {
                                e1i = i, e1j = j;
                                cnt++;
                            }
                            else if (cnt == 1)
                            {
                                e2i = i, e2j = j;
                                cnt++;
                            }
                        }
                    }

                    if (j == (2 * w - 1))
                    {
                        if (grid[i][j + 1] == ' ')
                        {
                            if (cnt == 0)
                            {
                                e1i = i, e1j = j;
                                cnt++;
                            }
                            else if (cnt == 1)
                            {
                                e2i = i, e2j = j;
                                cnt++;
                            }
                        }
                    }
                }
                else if (j == 1)
                {
                    if (grid[i][j - 1] == ' ')
                    {
                        if (cnt == 0)
                        {
                            e1i = i, e1j = j;
                            cnt++;
                        }
                        else if (cnt == 1)
                        {
                            e2i = i, e2j = j;
                            cnt++;
                        }
                    }
                }
                else if (j == (2 * w - 1))
                {
                    if (grid[i][j + 1] == ' ')
                    {
                        if (cnt == 0)
                        {
                            e1i = i, e1j = j;
                            cnt++;
                        }
                        else if (cnt == 1)
                        {
                            e2i = i, e2j = j;
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    if (e2i == -1)
    {
        e2i = e1i;
        e2j = e1j;
    }

    vector<vector<int>> d1 = bfs(e1i, e1j, grid);
    vector<vector<int>> d2 = bfs(e2i, e2j, grid);

    int ans = 0;
    for (int i = 1; i < (2 * h); i += 2)
    {
        for (int j = 1; j < (2 * w); j += 2)
        {
            ans = max(min(d1[i][j], d2[i][j]), ans);
        }
    }

    cout << ans + 1 << "\n";
}