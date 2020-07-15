#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    int bef = 4126;
    bool sorted = true;
    bool changed = false;
    while(n--) {
        int x, y; cin >> x >> y;
        if(x != y) {
            changed = true;
        }
        if(x > bef) {
            sorted = false;
        }
        bef = x;
    }

    if(changed) {
        cout << "rated\n";
    } else if(!changed && !sorted) {
        cout << "unrated\n";
    } else {
        cout << "maybe\n";
    }
    return 0;
}