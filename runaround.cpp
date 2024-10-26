

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <climits>
#include <string>

using namespace std;
typedef long long ll;

bool runaround(ll x)
{

    bool ok = true;
    string sx = to_string(x);

    set<char> chars;
    for (auto c : sx)
    {
        if (c == '0')
            return false;
        chars.insert(c);
    }
    if (chars.size() < sx.length())
        return false;

    int first_digit = sx[0] - '0';
    int first_idx = 0;
    int length = sx.length();
    int og = first_digit;
    int count = 0;
    set<int> indices;
    indices.insert(0);

    while (true)
    {
        int next_idx = (first_idx + first_digit) % length;
        int next_digit = sx[next_idx] - '0';

        if (first_digit == next_digit)
        {
            ok = false;
            break;
        }

        if (indices.count(next_idx))
        {
            if (next_idx != 0)
            {
                ok = false;
                break;
            }
            else if (next_idx == 0)
                break;
        }

        indices.insert(next_idx);

        first_digit = next_digit;
        first_idx = next_idx;
        count++;
    }

    return ok && (indices.size() == length);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    ll m;
    cin >> m;
    int ans = m;
    for (int i = m + 1; i <= (1e9); i++)
    {
        if (runaround(i))
        {

            ans = i;
            break;
        }
    }
    cout << ans << "\n";
}