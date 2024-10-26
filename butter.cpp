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
const int INF = 1e8;
int n, p, c;
int cow_present[1000];
vector<pair<int, int>> graph[1000];

int dijkstra(int start)
{
    vector<int> distance(p + 1, INF);
    priority_queue<pair<int, int>> pq;
    distance[start] = 0;
    pq.push({0, start});
    int min_path_sum = 0;
    while (!pq.empty())
    {
        auto [cur_dist, cur_node] = pq.top();
        pq.pop();
        cur_dist *= -1;
        if (cur_dist > distance[cur_node])
            continue;

        for (auto [nbr, weight] : graph[cur_node])
        {
            if (weight + cur_dist < distance[nbr])
            {
                distance[nbr] = weight + cur_dist;
                pq.push({-distance[nbr], nbr});
            }
        }
    }

    for (int i = 1; i <= p; i++)
    {
        min_path_sum += distance[i] * cow_present[i];
    }

    return min_path_sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);

    cin >> n >> p >> c;

    for (int i = 0; i < n; i++)
    {
        int cow_number;
        cin >> cow_number;
        cow_present[cow_number]++;
    }

    for (int i = 0; i < c; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        graph[v1].push_back({v2, weight});
        graph[v2].push_back({v1, weight});
    }

    int ans = INF;
    for (int i = 1; i <= p; i++)
    {

        int min_dist2 = dijkstra(i);
        ans = min({ans, min_dist2});
    }

    cout << ans << "\n";
}