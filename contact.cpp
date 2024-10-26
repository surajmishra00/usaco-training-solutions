

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
#include <queue>

using namespace std;
int a, b, n;
string emission;
map<string, int> counter;

int binary(string x)
{
    int ans = 0;
    int cur = 1;
    for (int i = x.size() - 1; i >= 0; i--)
    {
        ans += cur * (x[i] - '0');
        cur *= 2;
    }
    return ans;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    cin >> a >> b >> n;
    string ns;
    while (getline(cin, ns))
    {
        emission += ns;
    }

    for (int i = a; i <= min(b, (int)emission.size()); i++)
    {

        for (int j = 0; j < emission.size() - i + 1; j++)
        {
            // cout << i << " " << j << "\n";
            string cur_string = emission.substr(j, i);
            // cout << cur_string << "\n";
            counter[cur_string]++;
        }
    }

    map<int, vector<string>> freq;
    for (auto [pattern, count] : counter)
    {
        freq[count].push_back(pattern);
    }

    int count = 0;

    for (auto it = freq.rbegin(); it != freq.rend(); ++it)
    {
        if (count == n)
            break;
        auto vec = (*it).second;
        sort(vec.begin(), vec.end(), [](string v1, string v2)
             { if(v1.length() != v2.length()) return v1.length() < v2.length() ; 
             else return binary(v1) < binary(v2) ; });
        // vec = {
        //     "0",
        //     "0",
        //     "0",
        //     "0",
        //     "0",
        //     "0", "0"};

        cout << (*it).first << "\n";

        int cc = 0;

        while (cc < vec.size())
        {
            // if (cc % 6 == 0 && cc != 0)
            //     cout << "\n";
            cout << vec[cc];
            cc++;
            if (cc == vec.size() || cc % 6 == 0)
                cout << "\n";
            else
                cout << " ";
        }

        // cout << "\n";
        count++;
    }
}