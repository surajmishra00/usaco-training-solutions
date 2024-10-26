
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);

    ll v, n;
    cin >> v >> n;
    vector<ll> coins(v);
    for (ll i = 0; i < v; i++)
        cin >> coins[i];

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (auto coin : coins)
    {
        for (int i = coin; i <= n; i++)
        {
            dp[i] += dp[i - coin];
        }
    }

    cout << dp[n] << "\n";
}