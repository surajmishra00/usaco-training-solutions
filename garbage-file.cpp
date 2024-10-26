// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    // int b1[4];
    // int b2[4];
    // for(int i = 0; i < 4; i++) cin >> b1[i];
    // for(int i = 0; i < 4; i++) cin >> b2[i];

    // bool oy = (b1[3] <= b2[3]) && (b1[1] >= b2[1]);
    // bool ox = (b1[2] <= b2[2]) && (b1[0] >= b2[0]);

    // int oyn = max(0, min(b1[3], b2[3]) - max(b1[1], b2[1]));
    // int oxn = max(0, min(b1[2], b2[2]) - max(b1[0], b2[0]));

    // int xl = b1[2] - b1[0];
    // int yl = b1[3] - b1[1];

    // if((oyn == yl) && (oxn == xl)) {
    // 	cout << 0 << "\n";
    // } else if (oyn == yl) {
    // 	cout << yl*(xl - oxn) << "\n";
    // } else if(oxn == yl) {
    // 	cout << xl*(yl - oyn) << "\n";
    // } else {
    // 	cout << yl*xl << "\n";
    // }

    char farm[10][10];
    int bi, bj;
    int ri, rj;
    int li, lj;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> farm[i][j];
            if (farm[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
            if (farm[i][j] == 'L')
            {
                li = i, lj = j;
            }
            if (farm[i][j] == 'R')
            {
                ri = i, rj = j;
            }
        }
    }

    int ans = abs(bi - li) + abs(lj - bj) - 1;

    if (bi == ri && li == ri && (bj - rj) * (lj - rj) < 0)
        ans += 2;
    if (bj == rj && lj == rj && (bi - ri) * (li - ri) < 0)
        ans += 2;
    cout << ans << "\n";
}
