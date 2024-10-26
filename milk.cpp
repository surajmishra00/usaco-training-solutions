
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

    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> milks(m);
    for (int i = 0; i < m; i++)
    {
        int cost, amount;
        cin >> cost >> amount;
        milks[i] = {cost, amount};
    }

    sort(milks.begin(), milks.end());

    int total_milk = 0;
    int total_cost = 0;
    for (int i = 0; i < m; i++)
    {
        if (total_milk + milks[i].second <= n)
        {
            total_cost += milks[i].first * milks[i].second;
            total_milk += milks[i].second;
        }
        else
        {
            total_cost += (n - total_milk) * milks[i].first;
            total_milk = n;
            break;
        }
    }
    cout << total_cost << "\n";
}
