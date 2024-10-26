

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int a, b, c;
set<vector<int>> answers;

void solve(int ca, int cb, int cc, int count = 0)
{
    // cout << answers.size() << "\n";
    // cout << ca << " " << cb << " " << cc << " " << count << "\n";
    if (answers.find({ca, cb, cc}) != answers.end())
        return;
    answers.insert({ca, cb, cc});

    if (ca > 0)
    {
        // 1. Pour milk into bucket b
        {
            int ncb = min(b, cb + ca);
            int nca = ca - (ncb - cb);
            int ncc = cc;
            solve(nca, ncb, ncc, count + 1);
        }

        // 2. Pour milk into bucket c
        {
            int ncc = min(c, cc + ca);
            int nca = ca - (ncc - cc);
            int ncb = cb;
            solve(nca, ncb, ncc, count + 1);
        }
    }

    if (cb > 0)
    {
        // 1. Pour milk into bucket a
        {
            int nca = min(a, ca + cb);
            int ncb = cb - (nca - ca);
            int ncc = cc;
            solve(nca, ncb, ncc, count + 1);
        }

        // 2. Pour milk into bucket c
        {
            int nca = ca;
            int ncc = min(c, cc + cb);
            int ncb = cb - (ncc - cc);
            solve(nca, ncb, ncc, count + 1);
        }
    }

    if (cc > 0)
    {
        // 1. Pour milk into bucket a
        {
            int nca = min(a, ca + cc);
            int ncc = cc - (nca - ca);
            int ncb = cb;
            solve(nca, ncb, ncc, count + 1);
        }

        // 2. Pour milk into bucket b
        {
            int ncb = min(b, cb + cc);
            int ncc = cc - (ncb - cb);
            int nca = ca;
            solve(nca, ncb, ncc, count + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    cin >> a >> b >> c;
    solve(0, 0, c, 0);
    // cout << answers.size() << "\n";
    vector<int> res;
    for (auto el : answers)
    {
        if (el[0] == 0)
            res.push_back(el[2]);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << " ";
    }
    cout << res.back() << "\n";
}