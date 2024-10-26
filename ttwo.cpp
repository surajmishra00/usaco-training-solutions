

#include <bits/stdc++.h>
#include <ios>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);

    vector<vector<char>> forest(10, vector<char>(10));

    int ci = -1, cj = -1;
    int fi = -1, fj = -1;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> forest[i][j];
            if (forest[i][j] == 'C')
            {
                ci = i, cj = j;
            }

            if (forest[i][j] == 'F')
            {
                fi = i, fj = j;
            }
        }
    }

    int ans = 0;
    char cd = 0;
    char fd = 0;
    for (int time = 0; time <= 170000; time++)
    {
        if (ci == fi && cj == fj)
        {
            ans = time;
            break;
        }

        int nci, ncj;
        int nfi, nfj;
        if (cd == 0)
        {
            if (ci == 0 || forest[ci - 1][cj] == '*')
            {
                nci = ci;
                ncj = cj;
                cd = (cd + 1) % 4;
            }
            else
            {
                nci = ci - 1;
                ncj = cj;
            }
        }

        else if (cd == 1)
        {
            if (cj == 9 || forest[ci][cj + 1] == '*')
            {
                nci = ci;
                ncj = cj;
                cd = (cd + 1) % 4;
            }
            else
            {
                nci = ci;
                ncj = cj + 1;
            }
        }
        else if (cd == 2)
        {
            if (ci == 9 || forest[ci + 1][cj] == '*')
            {
                nci = ci;
                ncj = cj;
                cd = (cd + 1) % 4;
            }
            else
            {
                nci = ci + 1;
                ncj = cj;
            }
        }
        else if (cd == 3)
        {
            if (cj == 0 || forest[ci][cj - 1] == '*')
            {
                nci = ci;
                ncj = cj;
                cd = (cd + 1) % 4;
            }
            else
            {
                nci = ci;
                ncj = cj - 1;
            }
        }

        if (fd == 0)
        {
            if (fi == 0 || forest[fi - 1][fj] == '*')
            {
                nfi = fi;
                nfj = fj;
                fd = (fd + 1) % 4;
            }
            else
            {
                nfi = fi - 1;
                nfj = fj;
            }
        }

        else if (fd == 1)
        {
            if (fj == 9 || forest[fi][fj + 1] == '*')
            {
                nfi = fi;
                nfj = fj;
                fd = (fd + 1) % 4;
            }
            else
            {
                nfi = fi;
                nfj = fj + 1;
            }
        }

        else if (fd == 2)
        {
            if (fi == 9 || forest[fi + 1][fj] == '*')
            {
                nfi = fi;
                nfj = fj;
                fd = (fd + 1) % 4;
            }
            else
            {
                nfi = fi + 1;
                nfj = fj;
            }
        }

        else if (fd == 3)
        {
            if (fj == 0 || forest[fi][fj - 1] == '*')
            {
                nfi = fi;
                nfj = fj;
                fd = (fd + 1) % 4;
            }
            else
            {
                nfi = fi;
                nfj = fj - 1;
            }
        }

        ci = nci;
        cj = ncj;
        fi = nfi;
        fj = nfj;
    }
    // cout << if_meet << "\n";
    // cout << mtm << "\n";
    cout << ans << "\n";
}
