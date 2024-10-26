

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("frac1.in", "r", stdin);
    freopen("frac1  .out", "w", stdout);
    map<pair<int, int>, ld> m;
    m[{1, 1}] = 1;

    int n;
    cin >> n;
    for (int num = 0; num <= n; num++)
    {
        for (int den = num + 1; den <= n; den++)
        {
            int up = num;
            int down = den;
            while (gcd(up, down) > 1)
            {

                int g = gcd(up, down);
                up /= g;
                down /= g;
            }
            m[{up, down}] = ((ld)up * (ld)1.0) / ((ld)down * (ld)1.0);
        }
    }
    vector<pair<double, pair<int, int>>> answers;
    for (auto pair : m)
    {
        double value = pair.second;
        int num = pair.first.first;
        int den = pair.first.second;
        answers.push_back({value, {num, den}});
    }

    sort(answers.begin(), answers.end());
    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers[i].second.first << "/" << answers[i].second.second << "\n";
    }
}