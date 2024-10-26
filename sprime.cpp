

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <string>

using namespace std;
vector<int> answers;
int n;

bool if_prime(int x)
{
    if (x < 2)
        return false;
    if (x == 2)
        return true;

    for (int i = 2; i < int(sqrt(x)) + 1; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void generate(string cur)
{
    if (cur.length() == n)
    {
        answers.push_back(stoi(cur));
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        char ch = '0' + i;
        string nc = cur + ch;
        if (if_prime(stoi(nc)))
            generate(nc);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);

    cin >> n;
    generate("");
    for (auto num : answers)
        cout << num << "\n";
}
