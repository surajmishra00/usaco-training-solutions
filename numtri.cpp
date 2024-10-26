

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    int r;
    cin >> r;

    vector<int> cur(4001, 0);
    int lo = 2001;
    int hi = 1999;
    for (int i = 1; i <= r; i++)
    {
        // for (int j = lo; j <= hi; j += 2)
        //     cout << cur[j] << " ";
        // cout << "\n";

        vector<int> ncur(4001, 0);
        for (int idx = lo - 1; idx <= hi + 1; idx += 2)
        {
            cin >> ncur[idx];
            ncur[idx] = max(ncur[idx] + cur[idx - 1], ncur[idx] + cur[idx + 1]);
        }
        for (int k = 0; k < ncur.size(); k++)
            cur[k] = ncur[k];

        lo--;
        hi++;
    }
    int maxi = 0;
    for (int i = lo; i <= hi; i += 2)
    {
        maxi = max(maxi, cur[i]);
    }
    cout << maxi << "\n";
}