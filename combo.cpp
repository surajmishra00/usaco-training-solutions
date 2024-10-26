

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>

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

    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> l1(3);
    vector<int> l2(3);
    for (int i = 0; i < 3; i++)
        cin >> l1[i];
    for (int i = 0; i < 3; i++)
        cin >> l2[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                int d11 = min(abs(i - l1[0]), n - abs(i - l1[0]));
                int d12 = min(abs(j - l1[1]), n - abs(j - l1[1]));
                int d13 = min(abs(k - l1[2]), n - abs(k - l1[2]));

                int d21 = min(abs(i - l2[0]), n - abs(i - l2[0]));
                int d22 = min(abs(j - l2[1]), n - abs(j - l2[1]));
                int d23 = min(abs(k - l2[2]), n - abs(k - l2[2]));
                if (max({d11, d12, d13}) <= 2 || max({d21, d22, d23}) <= 2)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}