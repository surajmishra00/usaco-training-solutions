
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <climits>

using namespace std;

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    set<char> allowed;
    for (auto num : nums)
        allowed.insert('0' + num);
    int count = 0;

    for (auto a : nums)
    {
        for (auto b : nums)
        {
            for (auto c : nums)
            {
                for (auto d : nums)
                {
                    for (auto e : nums)
                    {
                        int p1 = (100 * a + 10 * b + c) * e;
                        int p2 = (100 * a + 10 * b + c) * d;
                        string ps1 = to_string(p1);
                        string ps2 = to_string(p2);

                        bool ok = true;
                        if (ps1.length() > 3)
                            ok = false;
                        if (ps2.length() > 3)
                            ok = false;

                        for (auto ch : ps1)
                        {
                            if (!allowed.count(ch))
                                ok = false;
                        }
                        for (auto ch : ps2)
                        {
                            if (!allowed.count(ch))
                                ok = false;
                        }

                        int res = 10 * p2 + p1;
                        string rsc = to_string(res);

                        if (rsc.length() > 4)
                            ok = false;
                        for(auto ch : rsc) {
                            if (!allowed.count(ch))
                                ok = false;
                        }

                        count += ok;
                        // if (ok)
                        // {
                        //     cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
                        // }
                    }
                }
            }
        }
    }
    cout << count << "\n";
}
