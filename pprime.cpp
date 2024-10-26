

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <string>

using namespace std;
vector<int> answers;
int a, b;

bool if_prime(int x)
{
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;

    for (int i = 3; (i * i) <= x; i += 2)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int convert(vector<int> &digits)
{
    int n = digits.size();
    int res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int power = n - 1 - i;
        int exp = 1;
        for (int j = 0; j < power; j++)
            exp *= 10;
        res += exp * digits[i];
    }
    return res;
}

void generate(int l, int r, vector<int> &digits)
{
    if (l > r)
    {
        int num = convert(digits);
        if (if_prime(num) && num <= b && num >= a)
        {
            answers.push_back(num);
        }
        return;
    }

    if (l == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            digits[l] = digits[r] = i;
            generate(l + 1, r - 1, digits);
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            digits[l] = digits[r] = i;
            generate(l + 1, r - 1, digits);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        vector<int> digits(i, 0);
        generate(0, i - 1, digits);
    }
    // cout << answers.size() << "\n";
    for (auto num : answers)
    {
        cout << num << "\n";
    }
}
