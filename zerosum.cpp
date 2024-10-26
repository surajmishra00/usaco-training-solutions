

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <climits>

using namespace std;

int n;
vector<string> ans;

int value(string exp)
{
    int res = 0;
    char sign = '+';
    string cur_num = "";

    for (auto c : exp)
    {
        // cout << res << " " << sign << " " << cur_num << " " << c << "\n";
        if (c == ' ')
            continue;

        if (c >= '0' && c <= '9')
        {
            cur_num += c;
            continue;
        }

        if (c == '+' || c == '-')
        {
            res += (sign == '+' ? stoi(cur_num) : -stoi(cur_num));
            cur_num = "";
            sign = c;
        }
    }

    res += (sign == '+' ? stoi(cur_num) : -stoi(cur_num));

    return res;
}

void generate(string cur, int num)
{
    char last = cur.back();
    if (last - '0' == n)
    {
        if (value(cur) == 0)
            ans.push_back(cur);
    }

    else
    {
        if (last >= '0' && last <= '9')
        {
            generate(cur + ' ', num);
            generate(cur + '+', num);
            generate(cur + '-', num);
        }

        else if (last == '+' || last == '-' || last == ' ')
        {
            generate(cur + to_string(num), num + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);

    cin >> n;
    generate("1", 2);
    sort(ans.begin(), ans.end());
    for (auto seq : ans)
    {
        cout << seq << "\n";
    }
}