
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <string>
#include <map>
#include <numeric>
#include <unordered_map>

using namespace std;
typedef long double ld;
typedef long long ll;

const int MOD = 9901;
int dp[500][500];

int fm(int a)
{

    int tmp = a / MOD;
    return a - (MOD * tmp);
    // return a % MOD;
}

void solve(ll n, ll k)
{
    if (n <= 0)
        return;

    if (k <= 0)
        return;

    if (n % 2 == 0)
    {
        dp[n][k] = 0;
        return;
    }

    if ((n < (2 * k - 1)))
    {
        dp[n][k] = 0;
        return;
    }

    if (n > ((ll)pow(2, k) - 1) && k < 10)
    {
        dp[n][k] = 0;
        return;
    }

    // Both trees have height k - 1
    for (int ln = 1; ln < n; ln++)
    {
        int rn = n - ln - 1;
        int l = fm(dp[ln][k - 1]);
        int r = fm(dp[rn][k - 1]);
        dp[n][k] = fm((dp[n][k] + (fm(l * r))));
    }

    // Left tree has height k - 1
    for (int rh = 1; rh < k - 1; rh++)
    {
        for (int ln = 1; ln < n; ln++)
        {
            int rn = n - ln - 1;
            int l = fm(dp[ln][k - 1]);
            int r = fm(dp[rn][rh]);
            dp[n][k] = fm((dp[n][k] + (fm(l * r))));
        }
    }

    // Right tree has height k - 1
    for (int lh = 1; lh < k - 1; lh++)
    {
        for (int ln = 1; ln < n; ln++)
        {
            int rn = n - ln - 1;
            int l = fm(dp[ln][lh]);
            int r = fm(dp[rn][k - 1]);
            dp[n][k] = fm((dp[n][k] + (fm(l * r))));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    dp[1][1] = 1;
    int n, k;
    cin >> n >> k;
    for (int i = 3; i <= n; i += 2)
    {
        for (int j = 0; j <= k; j++)
        {
            solve(i, j);
        }
    }
    cout << dp[n][k] << "\n";
}