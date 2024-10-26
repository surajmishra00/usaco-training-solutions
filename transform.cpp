
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

vector<vector<char>> rotate(vector<vector<char>> &p)
{
    int n = p.size();
    vector<vector<char>> g(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[j][n - 1 - i] = p[i][j];
        }
    }

    return g;
}

vector<vector<char>> reflect(vector<vector<char>> &p)
{
    int n = p.size();
    vector<vector<char>> g(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][n - 1 - j] = p[i][j];
        }
    }
    return g;
}

bool equal(vector<vector<char>> &p1, vector<vector<char>> &p2)
{
    int n = p1.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p1[i][j] != p2[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<char>> p(n, vector<char>(n));
    vector<vector<char>> np(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            p[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            np[i][j] = s[j];
        }
    }

    int ans = 7;
    bool ok = false;
    for (int i = 1; i <= 6; i++)
    {
        if (ok)
            break;
        vector<vector<char>> rp1 = rotate(p);
        vector<vector<char>> rp2 = rotate(rp1);
        vector<vector<char>> rp3 = rotate(rp2);
        vector<vector<char>> rfp = reflect(p);

        switch (i)
        {
        case 1:
        {
            if (equal(rp1, np))
            {
                ok = true;
                ans = 1;
                break;
            }
        }
        case 2:
        {
            if (equal(rp2, np))
            {
                ok = true;
                ans = 2;
                break;
            }
        }
        case 3:
        {
            if (equal(rp3, np))
            {
                ok = true;
                ans = 3;
                break;
            }
        }
        case 4:
        {
            if (equal(rfp, np))
            {
                ok = true;
                ans = 4;
                break;
            }
        }

        case 5:
        {
            vector<vector<char>> rfp = reflect(p);
            vector<vector<char>> rp1 = rotate(rfp);
            vector<vector<char>> rp2 = rotate(rp1);
            vector<vector<char>> rp3 = rotate(rp2);
            if (equal(rp1, np) || equal(rp2, np) || equal(rp3, np))
            {
                ok = true;
                ans = 5;
                break;
            }
        }
        case 6:
        {
            if (equal(p, np))
            {
                ok = true;
                ans = 6;
                break;
            }
        }
        case 7:
        {
            ok = true;
            ans = 7;
            break;
        }
        default:
            break;
        }
    }
    cout << ans << "\n";
}
