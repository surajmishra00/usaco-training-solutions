

#include <bits/stdc++.h>
using namespace std;

int digits(int num)
{
    return to_string(num).size();
}

int pr(int x)
{
    int ans = 1;
    for (int i = 0; i < x - 1; i++)
        ans *= 10;
    return ans;
}

string convert(int x)
{
    string ns = "";
    while (x > 0)
    {
        // cout << x << "\n";
        int dx = digits(x);
        int fd = to_string(x)[0] - '0';
        if (fd <= 3 && fd >= 1)
        {
            if (digits(x) == 1)
            {
                for (int j = 0; j < fd; j++)
                    ns += "I";
            }
            else if (digits(x) == 2)
            {
                for (int j = 0; j < fd; j++)
                    ns += "X";
            }
            else if (digits(x) == 3)
            {
                for (int j = 0; j < fd; j++)
                    ns += "C";
            }
            else if (digits(x) == 4)
            {
                for (int j = 0; j < fd; j++)
                    ns += "M";
            }

            x -= fd * (pr(dx));
        }

        else if (fd == 4)
        {
            if (digits(x) == 1)
            {
                ns += "IV";
            }
            else if (digits(x) == 2)
            {
                ns += "XL";
            }
            else if (digits(x) == 3)
            {
                ns += "CD";
            }

            x -= 4 * (pr(dx));
        }

        else if (fd >= 5 && fd <= 8)
        {
            if (digits(x) == 1)
            {
                ns += "V";
            }
            else if (digits(x) == 2)
            {
                ns += "L";
            }
            else if (digits(x) == 3)
            {
                ns += "D";
            }

            x -= 5 * (pr(dx));
        }

        else if (fd == 9)
        {
            if (digits(x) == 1)
            {
                ns += "IX";
            }
            else if (digits(x) == 2)
            {
                ns += "XC";
            }
            else if (digits(x) == 3)
            {
                ns += "CM";
            }

            x -= 9 * (pr(dx));
        }
    }
    return ns;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    int n;
    cin >> n;
    map<char, int> counter;

    counter['I'] = 0;
    counter['V'] = 0;
    counter['X'] = 0;
    counter['L'] = 0;
    counter['C'] = 0;
    counter['D'] = 0;
    counter['M'] = 0;

    for (int i = 1; i <= n; i++)
    {
        string s = convert(i);
        for (auto chr : s)
        {
            counter[chr]++;
        }
    }
    for (auto chr : {'I', 'V', 'X', 'L', 'C', 'D', 'M'})
    {
        if (counter[chr] == 0)
            break;
        cout << chr << " " << counter[chr] << "\n";
    }
}