
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
#include <queue>

using namespace std;

int g[200][200];
int n;

int mst()
{
    vector<bool> added(n, false);
    int mst_weight = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [cur_weight, cur_node] = pq.top();
        cur_weight *= -1;
        pq.pop();
        if (added[cur_node])
            continue;
        added[cur_node] = true;
        mst_weight += cur_weight;
        for (int j = 0; j < n; j++)
        {
            if (!added[j])
                pq.push({-g[cur_node][j], j});
        }
    }
    return mst_weight;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    cout << mst() << "\n";
}