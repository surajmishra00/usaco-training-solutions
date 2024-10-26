

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

    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);

    int b;
    cin >> b;
    initialize();

    for (int i = 1; i <= 300; i++)
    {
        string x = convert(i, b, "");
        string sq = convert(i * i, b, "");
        string nsq(sq.rbegin(), sq.rend());
        if (sq == nsq)
        {
            cout << x << " " << sq << "\n";
        }
    }
}
