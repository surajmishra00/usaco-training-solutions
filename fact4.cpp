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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);

    int n;
    cin >> n;
    int ans = 1;
    int cnt5 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp % 5 == 0)
        {
            cnt5++;
            tmp /= 5;
        }

        while (tmp % 2 == 0)
        {
            cnt2++;
            tmp /= 2;
        }

        ans = ((ans % 10) * (tmp % 10)) % 10;
    }

    cnt2 -= cnt5;
    if (cnt2 != 0)
    {
        if (cnt2 % 4 == 0)
            ans = ((ans % 10) * 6) % 10;
        else if (cnt2 % 4 == 1)
        {
            ans = ((ans % 10) * 2) % 10;
        }
        else if (cnt2 % 4 == 2)
        {
            ans = ((ans % 10) * 4) % 10;
        }
        else if (cnt2 % 4 == 3)
        {
            ans = ((ans % 10) * 8) % 10;
        }
    }

    cout << ans << "\n";
}