#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    if(m == 1) {
        cout << (m+1 <= n ? m+1 : m) << "\n";
    } else if(m == n) {
        cout << (m-1 >= 1 ? m-1 : m) << "\n";
    }
    else if(m <= n/2) {
        cout << m+1 << "\n";
    } else {
        cout << m-1 << "\n";
    }
    
    return 0;
}