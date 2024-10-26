

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cfloat>
#include <chrono>

using namespace std;
typedef long double ld;
int n;
// map<int, pair<float, float>> coords;
// vector<pair<float, float>> coords;
pair<float, float> coords[200];

vector<int> parent;
vector<int> sz;
const float INF = (float)1e8;

void printVec(vector<int> &vec)
{
    for (auto num : vec)
        cout << num << " ";
    cout << "\n";
}

int find(int node)
{
    return parent[node] == node ? node : parent[node] = find(parent[node]);
}

bool unite(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);
    if (x_parent == y_parent)
        return false;

    if (sz[y_parent] > sz[x_parent])
        swap(x_parent, y_parent);

    parent[y_parent] = x_parent;
    sz[x_parent] += y_parent;
    return true;
}
bool connected(int x, int y)
{
    return find(x) == find(y);
}

float distance(float xi, float xj, float yi, float yj) { return sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj)); }

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    cin >> n;
    parent.resize(n);
    sz.resize(n);
    fill(sz.begin(), sz.end(), 1);
    // coords.resize(n);
    for (int i = 0; i < n; i++)
    {
        ld xi, yi;
        cin >> xi >> yi;
        coords[i] = {xi, yi};
        // coords.emplace_back(xi, yi);
        parent[i] = i;
    }

    vector<vector<float>> dist(n, vector<float>(n, INF));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;

            char inp;
            cin >> inp;
            if (inp - '0' == 1)
            {
                ld p1x = coords[i].first, p1y = coords[i].second;
                ld p2x = coords[j].first, p2y = coords[j].second;
                dist[i][j] = distance(p1x, p2x, p1y, p2y);
                unite(i, j);
            }
        }
    }

    unordered_map<int, vector<int>> components;
    for (int i = 0; i < n; i++)
    {
        components[find(i)].push_back(i);
    }
    // for (auto pair : components)
    // {
    //     cout << pair.first << ": ";
    //     printVec(pair.second);
    // }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                float through_k = dist[i][k] + dist[k][j];
                if (through_k < dist[i][j])
                    dist[i][j] = through_k;
                // dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<vector<int>> comps;
    for (auto component : components)
    {
        comps.push_back(component.second);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << setprecision(6) << fixed << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    float ans = INF;

    int comp_count = comps.size();
    // auto start = chrono::high_resolution_clock::now();
    for (int c1 = 0; c1 < comp_count; c1++)
    {
        for (int c2 = c1 + 1; c2 < comp_count; c2++)
        {
            for (int v1 : comps[c1])
            {
                for (int v2 : comps[c2])
                {
                    if (dist[v1][v2] < INF)
                        continue;

                    vector<vector<float>> dist_temp = dist;
                    float tmp_d = distance(coords[v1].first, coords[v2].first, coords[v1].second, coords[v2].second);
                    dist_temp[v1][v2] = tmp_d;
                    dist_temp[v2][v1] = tmp_d;
                    float diameter = 0.0;

                    for (int k : {v1, v2})
                    {
                        for (int i = 0; i < n; i++)
                        {
                            for (int j = i + 1; j < n; j++)
                            {
                                // dist_temp[i][j] = min(dist_temp[i][j], dist_temp[i][k] + dist_temp[k][j]);
                                float tk = dist_temp[i][k] + dist_temp[k][j];
                                if (tk < dist_temp[i][j])
                                    dist_temp[i][j] = tk;
                                if (k == v2 && dist_temp[i][j] < INF)
                                {

                                    // diameter = max(diameter, dist_temp[i][j]);
                                    if (dist_temp[i][j] > diameter)
                                        diameter = dist_temp[i][j];
                                }
                            }
                        }
                    }

                    ans = min(ans, diameter);
                }
            }
        }
    }

    // for (int v1 = 0; v1 < n; v1++)
    // {
    //     for (int v2 = v1 + 1; v2 < n; v2++)
    //     {
    //         if (dist[v1][v2] < INF)
    //             continue;

    //         vector<vector<float>> dist_temp = dist;
    //         ld tmp_d = distance(coords[v1].first, coords[v2].first, coords[v1].second, coords[v2].second);
    //         dist_temp[v1][v2] = tmp_d;
    //         dist_temp[v2][v1] = tmp_d;
    //         float diameter = 0.0;

    //         for (int k : {v1, v2})
    //         {
    //             for (int i = 0; i < n; i++)
    //             {
    //                 for (int j = 0; j < n; j++)
    //                 {
    //                     dist_temp[i][j] = min(dist_temp[i][j], dist_temp[i][k] + dist_temp[k][j]);
    //                     if (k == v2)
    //                     {
    //                         if (dist_temp[i][j] < INF)
    //                             diameter = max(diameter, dist_temp[i][j]);
    //                     }
    //                 }
    //             }
    //         }

    //         ans = min(ans, diameter);
    //     }
    // }
    cout << fixed << setprecision(6) << ans << "\n";
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double> duration = end - start;
    // cout << duration.count() << "\n";
}