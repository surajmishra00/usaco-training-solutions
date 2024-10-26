

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("usaco-training.in", "r", stdin);
    // freopen("usaco-training.out", "w", stdout);

    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int n;
    string necklace;
    cin >> n >> necklace;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int front = 0;
        int back = 0;
        int cur = 0;
        for (int j = i; j < (i + n); j++)
        {
            if (necklace[(j + n) % n] == 'b' || (necklace[(j + n) % n] == 'w'))
            {
                cur++;
            }
            else
            {
                break;
            }
        }
        front = max(front, cur);
        cur = 0;
        for (int j = i; j < (i + n); j++)
        {
            if (necklace[(j + n) % n] == 'r' || (necklace[(j + n) % n] == 'w'))
            {
                cur++;
            }
            else
            {
                break;
            }
        }
        front = max(front, cur);
        cur = 0;
        for (int j = i - 1; j > (i - 1 - n); j--)
        {
            if (necklace[(j + n) % n] == 'b' || (necklace[(j + n) % n] == 'w'))
            {
                cur++;
            }
            else
            {
                break;
            }
        }
        back = max(back, cur);
        cur = 0;
        for (int j = i - 1; j > (i - 1 - n); j--)
        {
            if (necklace[(j + n) % n] == 'r' || (necklace[(j + n) % n] == 'w'))
            {
                cur++;
            }
            else
            {
                break;
            }
        }
        back = max(back, cur);
        cur = 0;
        ans = max(ans, back + front);
    }
    cout << min(ans, n) << "\n";
}
