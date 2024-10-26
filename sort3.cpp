

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <string>
#include <map>
#include <numeric>

using namespace std;
typedef long double ld;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> sa(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sa[i] = a[i];
    }

    sort(sa.begin(), sa.end());
    int f1 = 0;
    int f2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (sa[i] == 2)
        {
            f1 = i;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (sa[i] == 3)
        {
            f2 = i;
            break;
        }
    }

    int swaps = 0;
    for (int i = 0; i < f1; i++)
    {
        if (a[i] == 1)
            continue;
        else if (a[i] == 2)
        {
            for (int j = f1; j < f2; j++)
            {
                if (a[j] == 1)
                {
                    swap(a[i], a[j]);
                    swaps++;
                    break;
                }
            }
        }

        else if (a[i] == 3)
        {
            for (int j = f2; j < n; j++)
            {
                if (a[j] == 1)
                {
                    swap(a[i], a[j]);
                    swaps++;
                    break;
                }
            }
        }
    }

    for (int j = f1; j < f2; j++)
    {
        if (a[j] == 2 || a[j] == 1)
            continue;
        else if (a[j] == 3)
        {
            for (int k = f2; k < n; k++)
            {
                if (a[k] == 2)
                {
                    swap(a[j], a[k]);
                    swaps++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < f1; i++)
    {
        if (a[i] == 2 || a[i] == 3)
        {
            swaps += 2;
        }
    }
    cout << swaps << "\n";
}