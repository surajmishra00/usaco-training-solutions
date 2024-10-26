
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

    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> hills(n);
    for (int i = 0; i < n; i++)
        cin >> hills[i];

    int cost = INT_MAX;
    for (int i = 0; i <= 100; i++)
    {
        int tmp = 0;
        for (int j = 0; j < n; j++)
        {
            if (hills[j] <= i)
            {
                tmp += (i - hills[j]) * (i - hills[j]);
            }
            else
            {
                if (hills[j] - i > 17)
                {
                    tmp += (hills[j] - i - 17) * (hills[j] - i - 17);
                }
            }
        }
        cost = min(cost, tmp);
    }
    cout << cost << "\n";
}
