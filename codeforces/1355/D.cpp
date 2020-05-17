#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, s; cin >> n >> s;
    if(s-n <= n-1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        for(int i = 0; i < n-1; i++)
            cout << "1 ";
        cout << s-n+1 << "\n";
        cout << s-n << "\n";
    }
    
    return 0;
}