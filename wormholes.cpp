
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x{};
    int y{};
};

int n;
vector<Point> points;
vector<bool> chosen;
vector<pair<int, int>> subset;
vector<vector<pair<int, int>>> subsets;

void generate()
{
    bool c1 = true;
    for (int i = 0; i < n; i++)
    {
        if (!chosen[i])
            c1 = false;
    }

    if (c1)
    {
        subsets.push_back(subset);
    }
    else
    {
        int fp = -1;
        for (int i = 0; i < n; i++)
        {
            if (!chosen[i])
            {
                fp = i;
                break;
            }
        }
        chosen[fp] = true;
        for (int i = fp + 1; i < n; i++)
        {
            if (!chosen[i])
            {
                subset.emplace_back(fp, i);
                chosen[i] = true;
                generate();
                chosen[i] = false;
                subset.pop_back();
            }
        }
        chosen[fp] = false;
    }
}

void printSubsets(vector<vector<pair<int, int>>> &subsets)
{
    for (int i = 0; i < subsets.size(); i++)
    {
        vector<pair<int, int>> ss = subsets[i];
        for (auto pair : ss)
        {
            cout << "{ " << pair.first << ", " << pair.second << " }";
        }
        cout << "\n";
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);

    cin >> n;
    points.resize(n);
    chosen.resize(n);
    fill(chosen.begin(), chosen.end(), false);

    for (int i = 0; i < n; i++)
    {
        int xi, yi;
        cin >> xi >> yi;
        points[i] = Point{xi, yi};
    }
    generate();
    int ans = 0;
    for (int i = 0; i < subsets.size(); i++)
    {
        vector<pair<int, int>> ss = subsets[i];
        vector<int> next_on_right(n, -1);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (points[k].x > points[j].x && points[k].y == points[j].y)
                {
                    if (next_on_right[j] == -1 || points[next_on_right[j]].x - points[j].x > points[k].x - points[j].x)
                    {
                        next_on_right[j] = k;
                    }
                }
            }
        }
        int ok = false;
        for (int start = 0; start < n; start++)
        {
            int pos = start;
            for (int count = 0; count < n; count++)
            {
                int nor = next_on_right[pos];
                if (nor == -1)
                {
                    pos = -1;
                    break;
                }
                else
                {
                    for (auto pair : ss)
                    {
                        if (pair.first == nor)
                        {
                            pos = pair.second;
                            break;
                        }

                        if (pair.second == nor)
                        {
                            pos = pair.first;
                            break;
                        }
                    }
                }
            }
            if (pos != -1)
                ok = true;
        }
        ans += ok;
    }
    cout << ans << "\n";
}
