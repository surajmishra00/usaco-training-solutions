

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
typedef long long ll;

int hamming(int x, int y, int b)
{
    int dist = 0;
    for (int i = 0; i < b; i++)
    {
        int b1 = (1 << i) & x;
        int b2 = (1 << i) & y;
        if (b1 != b2)
            dist++;
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);

    int n, b, d;
    cin >> n >> b >> d;
    vector<bool> vis(1 << b, false);

    int count = 1;
    vector<int> cur = {0};
    vis[0] = true;
    while (count < n)
    {
        for (int i = 1; i < (1 << b); i++)
        {
            if (vis[i])
                continue;
            vis[i] = true;
            bool ok = true;
            for (auto num : cur)
            {
                if (hamming(num, i, b) < d)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                cur.push_back(i);
                count++;
            }
        }
    }
    sort(cur.begin(), cur.end());
    for (int i = 0; i < n - 1; i++)
    {
        cout << cur[i];
        if ((i + 1) % 10 == 0)
            cout << "\n";
        else
            cout << " ";
    }
    cout << cur[n - 1] << "\n";
}