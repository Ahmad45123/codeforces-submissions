#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string s; cin >> s;
    int n = s.size();

    cout << "3\n";
    cout << "R " << n-1 << "\n";
    cout << "L " << n << "\n";
    cout << "L 2\n";
    
    return 0;
}