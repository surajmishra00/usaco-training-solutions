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
const int INF = INT_MAX;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);

    int k, n;
    cin >> k >> n;
    vector<int> primes(k);
    for (int i = 0; i < k; i++)
        cin >> primes[i];
    vector<int> ans = {1};

    for (int i = 0; i < n; i++)
    {
        int mini = INF;
        int last = ans.back();
        for (auto prime : primes)
        {
            if (prime > last)
                mini = min(mini, prime);

            int cur = (last / prime) + 1;
            auto idx = lower_bound(ans.begin(), ans.end(), cur) - ans.begin();
            if (idx == ans.size())
                continue;

            mini = min(mini, ans[idx] * prime);
        }
        ans.push_back(mini);
    }
    // for (auto num : ans)
    //     cout << num << " ";
    // cout << "\n";
    cout << ans[n] << "\n";
}