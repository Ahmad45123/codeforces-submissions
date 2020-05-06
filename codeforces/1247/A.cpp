#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int a, b; cin >> a >> b;
    if(a == 9 && b == 1)
        cout << "9 10\n";
    else if(b-a == 1)
        cout << a << " " << b << "\n";
    else if(b-a == 0)
        cout << a << 0 << " " << b << 1 << "\n";
    else
        cout << -1 << "\n";
    
    return 0;
}