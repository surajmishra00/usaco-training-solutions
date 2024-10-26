

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cfloat>
#include <chrono>

using namespace std;
typedef long double ld;
int a, b;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    while (a != 0)
    {
        int tmp = a;
        a = b % a;
        b = tmp;
    }
    return b;
}

int period_length(int b)
{
    for (auto div : {2, 5})
    {
        while (b % div == 0)
            b /= div;
    }

    if (b == 1)
        return 0;

    int cnt = 1;
    int cur = 10;

    while (cur % b != 1)
    {
        cur = ((cur % b) * (10 % b)) % b;
        cnt++;
    }

    return cnt;
}

bool period_free(int b)
{

    int tmp = b;
    for (auto div : {2, 5})
    {
        while (tmp % div == 0)
        {
            tmp /= div;
        }
    }
    return tmp == 1;
}

string convert(int a, int b)
{
    string ans = "";
    if (b == 1)
    {
        ans += to_string(a) + '.' + '0';
        return ans;
    }

    else if (period_free(b))
    {
        int div = a / b;
        a -= (b * div);
        ans += to_string(div) + '.';
        int cnt = 0;
        while (a != 0)
        {
            if (a < b)
            {
                a *= 10;
                cnt += 1;
            }
            else
            {
                for (int k = 0; k < cnt - 1; k++)
                    ans += '0';
                ans += to_string(a / b);
                a -= (b * (a / b));
                cnt = 0;
            }
        }
    }

    else
    {
        int pl = period_length(b);
        int div = a / b;
        a -= (b * div);
        ans += to_string(div) + '.';
        int bdl = ans.length();
        int cnt = 0;
        int cur_streak = 0;
        while (cur_streak < pl)
        {
            if (a < b)
            {
                a *= 10;
                cnt += 1;
            }
            else
            {
                for (int k = 0; k < cnt - 1; k++)
                {
                    if (cur_streak == pl)
                        break;
                    ans += '0';
                    int idx = ans.length() - 1;
                    if (idx - pl >= bdl)
                    {
                        if (ans[idx] == ans[idx - pl])
                            cur_streak++;
                        else
                            cur_streak = 0;
                    }
                }
                if (cur_streak == pl)
                    break;
                ans += to_string(a / b);
                int idx = ans.length() - 1;
                if (idx >= pl + bdl)
                {
                    if (ans[idx] == ans[idx - pl])
                        cur_streak++;
                    else
                        cur_streak = 0;
                }

                a -= (b * (a / b));
                cnt = 0;
            }
        }

        // for (int i = 0; i < ans.length(); i += 76)
        // {
        //     for (int j = i; j < min(i + 76, (int)ans.length()); j++)
        //         cout << ans[j];
        //     cout << "\n";
        // }
        // cout << ans[ans.length() - pl] << "\n";
        // cout << bdl << "\n";
        // cout << ans << "\n";
        // cout << ans.back() << "\n";
        string res(ans.begin(), ans.begin() + ans.length() - 2 * pl);
        // cout << res << "\n";
        string res2(ans.begin() + ans.length() - 2 * pl, ans.begin() + ans.length() - pl);
        res += '(' + res2 + ')';
        // for (int i = 0; i < res.length(); i += 76)
        // {
        // for (int j = i; j < min(i + 76, (int)res.length()); j++)
        //     cout << res[j];
        // cout << "\n";
        // }
        // string res3(ans.begin() + ans.length() - pl, ans.begin() + ans.length());
        // for (int i = 0; i < res3.length(); i += 76)
        // {
        // for (int j = i; j < min(i + 76, (int)res3.length()); j++)
        //     cout << res3[j];
        // cout << "\n";
        // }

        return res;
    }

    return ans;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    cin >> a >> b;
    int g = gcd(a, b);
    a = a / g, b = b / g;
    // cout << period_free(b) << "\n";
    // cout << convert(a, b) << "\n";

    int max_num = 3, max_period_length = 1;

    string ans = convert(a, b);
    for (int i = 0; i < ans.length(); i += 76)
    {
        for (int j = i; j < min(i + 76, (int)ans.length()); j++)
            cout << ans[j];
        cout << "\n";
    }
}