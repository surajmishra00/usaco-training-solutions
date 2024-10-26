

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

map<char, string> f = {
    {'2', "ABC"},
    {'3', "DEF"},
    {'4', "GHI"},
    {'5', "JKL"},
    {'6', "MNO"},
    {'7', "PRS"},
    {'8', "TUV"},
    {'9', "WXY"}};

void generate(int idx, string s, vector<string> &ans, string cur, set<string> &names)
{
    if (idx == s.length())
    {
        if (names.find(cur) != names.end())
            ans.push_back(cur);
        return;
    }

    for (auto chr : f[s[idx]])
    {
        generate(idx + 1, s, ans, cur + chr, names);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream inputFile("dict.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    string name;
    vector<string> names;

    while (getline(inputFile, name))
    {
        names.push_back(name);
    }

    inputFile.close();

    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    string s;
    cin >> s;
    int count = 0;
    for (auto name : names)
    {
        if (name.length() != s.length())
            continue;
        
        


    }
}
