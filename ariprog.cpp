

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    unordered_set<int> bisquares;
    vector<int> bs;
    for (int p = 0; p <= m; p++)
    {
        for (int q = 0; q <= m; q++)
        {
            bisquares.insert((p * p) + (q * q));
        }
    }
    for (auto elem : bisquares)
        bs.push_back(elem);
    sort(bs.begin(), bs.end());
    int sz = bs.size();
    vector<pair<int, int>> answers;
    for (int first = 0; first < sz; first++)
    {
        for (int last = first + 1; last < sz; last++)
        {
            if ((bs[last] - bs[first]) % (n - 1) != 0)
                continue;
            int d = (bs[last] - bs[first]) / (n - 1);
            int ok = true;
            for (int i = bs[first] + d; i <= bs[last] - d; i += d)
            {
                if (bisquares.find(i) == bisquares.end())
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                answers.emplace_back(d, bs[first]);
        }
    }
    sort(answers.begin(), answers.end());
    if (answers.size() == 0)
        cout << "NONE" << "\n";
    else
    {
        for (auto pair : answers)
        {
            cout << pair.second << " " << pair.first << "\n";
        }
    }
}