#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int x, y; cin >> x >> y;
    int rem = 6-max(x, y)+1;
    switch (rem)
    {
    case 0:
        cout << "0/1\n";
        break;
    case 1:
        cout << "1/6\n";
        break;
    case 2:
        cout << "1/3\n";
        break;
    case 3:
        cout << "1/2\n";
        break;
    case 4:
        cout << "2/3\n";
        break;
    case 5:
        cout << "5/6\n";
        break;
    case 6:
        cout << "1/1\n";
        break;
    
    default:
        break;
    }
    
    return 0;
}