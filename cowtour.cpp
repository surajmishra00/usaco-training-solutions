

// In this directory, this file contains the correct solution to the Cow Tours Problem in USACO Training Gateway, Section 2.4;
// Other files in this directory resembling the name do not contain the correct solution;

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
const float INF = (float)1e9;

int parent[200];
int sz[200];
int n;

double dist[200][200];
double max_dist[200];
double   farthest[200]; 
pair<double, double> coords[200];

double distance(double xi, double yi, double xj, double yj) { return sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj)); }

int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
bool unite(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent)
        return false;

    if (sz[x_parent] < sz[y_parent])
        swap(x_parent, y_parent);

    parent[y_parent] = x_parent;
    sz[x_parent] += sz[y_parent];
    return true;
}

bool connected(int x, int y) { return find(x) == find(y); }

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        double xi, yi;
        cin >> xi >> yi;
        coords[i] = {xi, yi};
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char cn;
            cin >> cn;
            if (cn - '0' == 1)
            {
                unite(i, j);
                auto [xi, yi] = coords[i];
                auto [xj, yj] = coords[j];

                dist[i][j] = distance(xi, yi, xj, yj);
            }
        }
    }

    // debugging
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << fixed << setprecision(2) << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        farthest[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] < INF)
            {
                farthest[i] = max(farthest[i], dist[i][j]);
                int ip = find(i);
                max_dist[ip] = max(max_dist[ip], dist[i][j]);
            }
        }
    }

    double ans = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (connected(i, j))
                continue;
            auto [xi, yi] = coords[i];
            auto [xj, yj] = coords[j];

            double diameter = max({farthest[i] + farthest[j] + distance(xi, yi, xj, yj), max_dist[find(i)], max_dist[find(j)]});
            ans = min(ans, diameter);
        }
    }
    cout << fixed << setprecision(6) << ans << "\n";
}