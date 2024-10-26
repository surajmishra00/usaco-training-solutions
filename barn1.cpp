

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <climits>

using namespace std;

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    int m, s, c;
    cin >> m >> s >> c;
    vector<int> stalls(c);
    for (int i = 0; i < c; i++)
        cin >> stalls[i];

    sort(stalls.begin(), stalls.end());

    vector<int> difs;
    for (int i = 1; i < c; i++)
    {
        difs.push_back(stalls[i] - stalls[i - 1]);
    }

    sort(difs.rbegin(), difs.rend());
    int ans = 0;
    for (int i = 0; i < min(m - 1, (int)difs.size()); i++)
    {
        ans += difs[i] - 1;
    }

    int res = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end()) + 1 - ans;

    cout << res << "\n";
}
