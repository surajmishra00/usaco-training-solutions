

#include <bits/stdc++.h>
using namespace std;
int n, clicks;
set<string> configs;
string config = " ";

void toggle(int button)
{
    // int x = config.length();
    // int n = x - 1;
    if (button == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (config[i] == '0')
                config[i] = '1';
            else if (config[i] == '1')
                config[i] = '0';
        }
    }

    if (button == 2)
    {
        for (int i = 1; i <= n; i += 2)
        {
            if (config[i] == '0')
                config[i] = '1';
            else if (config[i] == '1')
                config[i] = '0';
        }
    }

    if (button == 3)
    {
        for (int i = 2; i <= n; i += 2)
        {
            if (config[i] == '0')
                config[i] = '1';
            else if (config[i] == '1')
                config[i] = '0';
        }
    }

    if (button == 4)
    {
        for (int i = 1; i <= n; i += 3)
        {
            if (config[i] == '0')
                config[i] = '1';
            else if (config[i] == '1')
                config[i] = '0';
        }
    }
}

void generate(int button, int count)
{
    if (button == 5)
    {
        // cout << count << "" << config << "\n";
        if (count <= clicks)
        {
            configs.insert(config);
        }
    }
    else
    {
        // cout << "config: " << "no button pressed " << config << "\n";
        generate(button + 1, count);
        toggle(button);
        // cout << "config: " << button << " pressed " << config << "\n";
        generate(button + 1, count + 1);
        toggle(button);
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);

    cin >> n >> clicks;
    string s = " ";
    for (int i = 1; i <= n; i++)
        s += "#";

    int x;
    cin >> x;
    while (x != -1)
    {
        s[x] = '1';
        cin >> x;
    }

    x = -2;
    cin >> x;
    while (x != -1)
    {
        s[x] = '0';
        cin >> x;
    }

    for (int i = 1; i <= n; i++)
        config += '1';

    generate(1, 0);

    vector<string> ans;
    for (auto con : configs)
    {
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '#')
                continue;
            else
            {
                if (con[i] != s[i])
                {
                    ok = false;
                    break;
                }
            }
        }

        if (ok)
            ans.push_back(con);
    }
    // cout  << s << "\n";
    if (ans.size() == 0)
        cout << "IMPOSSIBLE\n";
    else
        for (auto lamp : ans)
            cout << lamp.substr(1) << "\n";
}
