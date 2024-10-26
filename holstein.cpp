

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <string>
#include <map>
#include <numeric>

using namespace std;
typedef long double ld;

int v, g;
vector<int> min_req;
vector<vector<int>> feeds;
vector<vector<int>> subsets;

void solve()
{
    for (int i = 0; i < (1 << g); i++)
    {
        vector<int> subset;
        for (int j = 0; j < g; j++)
        {
            if (((1 << j) & i) != 0)
            {
                subset.push_back(j);
            }
        }
        vector<int> req(v);

        for (auto idx : subset)
        {
            vector<int> cur_feed = feeds[idx];
            for (int k = 0; k < v; k++)
                req[k] += cur_feed[k];
        }

        bool ok = true;
        for (int k = 0; k < v; k++)
        {
            if (min_req[k] > req[k])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            subsets.push_back(subset);
    }
    int min_length = 100;

    for (int i = 0; i < subsets.size(); i++)
    {
        min_length = min(min_length, (int)subsets[i].size());
    }

    vector<vector<int>> new_subsets;
    for (int i = 0; i < subsets.size(); i++)
    {
        if (subsets[i].size() == min_length)
            new_subsets.push_back(subsets[i]);
    }
    sort(new_subsets.begin(), new_subsets.end());
    vector<int> ans = new_subsets[0];
    cout << ans.size() << " ";
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << ans.back() + 1;
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    cin >> v;
    min_req.resize(v);
    for (int i = 0; i < v; i++)
        cin >> min_req[i];
    cin >> g;
    for (int i = 0; i < g; i++)
    {
        vector<int> feed(v);
        for (int j = 0; j < v; j++)
            cin >> feed[j];
        feeds.push_back(feed);
    }
    solve();
}