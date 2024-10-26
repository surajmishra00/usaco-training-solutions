
#include <bits/stdc++.h>
using namespace std;
// int n;
// string exp = "1";

// int calculate()
// {
//     int ans = 0;
//     int last = 1;
//     char sign = '+'
//     for(int i = 1; i <= exp.length(); i++)
//     {
//         if (exp[i] == '+' || exp[i] == '-')
//         {
//             if(sign == '+') ans += last;
//             else if(sign == '-') ans -= last;
//         }
//     }
// }

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    vector<string> primitives;
    string primitive;
    cin >> primitive;
    while (primitive != ".")
    {
        primitives.push_back(primitive);
        cin >> primitive;
    }

    string sequence = "";
    string s;
    while (cin >> s)
    {
        sequence += s;
    }

    int n = sequence.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto word : primitives)
        {
            int pl = word.length();
            if ((i - pl) >= 0)
            {
                string subs = sequence.substr(i - pl, pl);
                dp[i] = dp[i] || (dp[i - pl] && (subs == word));
                if (dp[i])
                    ans = max(ans, i);
            }
        }
    }
    // for(auto v : dp) cout << v << " ";
    // cout << "\n";
    cout << ans << "\n";
}