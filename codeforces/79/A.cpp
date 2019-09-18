#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int x, y;
    
    cin >> x >> y;
    int cur = 1; //0 = Ciel
    
    for(;;) {
        //Ciel turn
        cur = !cur;
        if(cur == 0) {
            if(x >= 2 && y >= 2) {
                x -= 2;
                y -= 2;
            } else if(x >= 1 && y >= 12) {
                x -= 1;
                y -= 12;
            } else if(x == 0 && y >= 22) {
                y -= 22;
            } else {
                break;
            }
        } else {
            if(y >= 22) {
                y -= 22;
            } else if(x >= 1 && y >= 12) {
                x -= 1;
                y -= 12;
            } else if(x >= 2 && y >= 2) {
                x -= 2;
                y -= 2;
            } else {
                break;
            }
        }
    }

    if(cur) {
        cout << "Ciel\n";
    } else {
        cout << "Hanako\n";
    }

    return 0;
}