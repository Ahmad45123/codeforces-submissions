#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int getDiff(string a, string b) {
    map<string, int> days;
    days["saturday"] = 0;
    days["sunday"] = 1;
    days["monday"] = 2;
    days["tuesday"] = 3;
    days["wednesday"] = 4;
    days["thursday"] = 5;
    days["friday"] = 6;
    if(days[b] >= days[a])
        return days[b]-days[a];
    else
        return 6-days[a]+days[b]+1;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string one, two; cin >> one >> two;
    int diff = getDiff(one, two);
    if(diff == 0 || diff == 2 || diff == 3)
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}