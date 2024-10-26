
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, char> pic;

void dijkstra(map<char, vector<pic>> g)
{
    map<char, int> distance;
    for (char i = 'a'; i <= 'z'; i++)
    {
        distance[i] = (int)1e8;
    }

    for (char i = 'A'; i <= 'Z'; i++)
    {
        distance[i] = (int)1e8;
    }
    distance['Z'] = 0;

    priority_queue<pic> frontier;
    frontier.push({0, 'Z'});

    while (!frontier.empty())
    {
        auto cur = frontier.top();
        int cur_dist = -cur.first;
        char cur_node = cur.second;
        frontier.pop();

        if (distance[cur_node] < cur_dist)
            continue;

        auto nbrs = g[cur_node];
        for (auto nbr : nbrs)
        {
            int nbr_dist = nbr.first;
            int nbr_node = nbr.second;
            if (nbr_dist + cur_dist < distance[nbr_node])
            {
                distance[nbr_node] = nbr_dist + cur_dist;
                frontier.push({-distance[nbr_node], nbr_node});
            }
        }
    }
    int mini = 1e8;
    char res = 'A';
    for (char i = 'A'; i < 'Z'; i++)
    {
        if (distance[i] < mini)
        {
            mini = distance[i];
            res = i;
        }
    }

    cout << res << " " << mini << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);

    int paths;
    cin >> paths;
    map<char, vector<pic>> g;

    for (int i = 0; i < paths; i++)
    {
        char u, v;
        int dist;
        cin >> u >> v >> dist;

        g[u].push_back({dist, v});
        g[v].push_back({dist, u});
    }

    dijkstra(g);
}