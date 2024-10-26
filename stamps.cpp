
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
int k, n;
int stamp_values[55];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);

    cin >> k >> n;
    for (int i = 0; i < n; i++)
        cin >> stamp_values[i];

    sort(stamp_values, stamp_values + n);
    int max_stamp_value = stamp_values[n - 1];
    int dp_size = max_stamp_value * k + 1;
    vector<int> dp(dp_size, 250);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {

        for (int j = stamp_values[i - 1]; j <= dp_size; j++)
        {
            dp[j] = min(dp[j], dp[j - stamp_values[i - 1]] + 1);
        }
    }

    int streak = 0;
    for (int i = 1; i <= max_stamp_value * k; i++)
    {
        if (dp[i] <= k)
            streak++;
        else
            break;
    }
    cout << streak << "\n";
}