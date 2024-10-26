
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
int m, n;
pair<int, int> types[10005];
int dp[10005];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);

    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int points, minutes;
        cin >> points >> minutes;

        types[i] = {points, minutes};
    }

    for (int i = 1; i <= n; i++)
    {
        auto [points, minutes] = types[i - 1];
        for (int j = minutes; j <= m; j++)
        {
            dp[j] = max(dp[j - minutes] + points, dp[j]);
        }
    }

    cout << dp[m] << "\n";
}