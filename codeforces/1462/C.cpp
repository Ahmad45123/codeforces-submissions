#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        if(x <= 9)
            cout << x << "\n";
        else if(x > 9 && x <= 17)
            cout << x-9 << "9\n";
        else if(x > 17 && x <= 24)
            cout << x-17 << "89\n";
        else if(x > 24 && x <= 30)
            cout << x-24 << "789\n";
        else if(x > 30 && x <= 35)
            cout << x-30 << "6789\n";
        else if(x > 35 && x <= 39)
            cout << x-35 << "56789\n";
        else if(x > 39 && x <= 42)
            cout << x-39 << "456789\n";
        else if(x > 42 && x <= 44)
            cout << x-42 << "3456789\n";
        else if(x > 44 && x <= 45)
            cout << x-44 << "23456789\n";
        else if(x > 45)
            cout << "-1\n";
    }
    
    return 0;
}