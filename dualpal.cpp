
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

map<int, char> f;

void initialize()
{
    for (int i = 0; i <= 9; i++)
    {
        f[i] = '0' + i;
    }

    char cur = 'A';
    for (int i = 10; i <= 20; i++)
    {
        f[i] = cur + i - 10;
    }
}

string convert(int x, int b, string acc)
{
    if (x == 0)
    {
        if (acc.empty())
            return "0";
        else
            return acc;
    }

    return convert(x / b, b, f[x % b] + acc);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    initialize();

    int n, s;
    cin >> n >> s;
    int count = 0;
    int cur = s + 1;
    while (count < n)
    {
        int tmp = 0;
        for (int i = 2; i <= 10; i++)
        {
            string s = convert(cur, i, "");
            string rs(s.rbegin(), s.rend());
            if (s == rs)
            {
                tmp++;
                // cout << cur << " " << i << " " << s << "\n";
            }
        }
        if (tmp >= 2)
        {
            count++;
            cout << cur << "\n";
        }
        cur++;
    }
}
