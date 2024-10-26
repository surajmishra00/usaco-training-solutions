

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

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("subset.in", "r", stdin);
    // freopen("subset.out", "w", stdout);

    ll n;
    cin >> n;

    ll summ = n * (n + 1) / 2;
    if (summ & 1)
    {

        cout << 0 << "\n";
    }
    else
    {
        summ /= 2;
        vector<ll> ways(summ + 1, 0);
        ways[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            vector<ll> new_ways(summ + 1, 0);
            for (ll j = 0; j <= summ; j++)
            {
                new_ways[j] = ways[j];
                if ((j - i) >= 0)
                    new_ways[j] += ways[j - i];
            }
            for (ll j = 0; j <= summ; j++)
                ways[j] = new_ways[j];
        }
        cout << ways[summ] / 2 << "\n";
    }
}