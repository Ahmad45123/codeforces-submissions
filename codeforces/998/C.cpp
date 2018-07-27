#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    ll n, x, y; cin >> n >> x >> y;
    string num; cin >> num;

    bool passedZero = false;

    ll totalX = 0; ll totalY = 0;
    for(ll i = 0; i < n; i++) {
        if(num[i] == '0')
            passedZero = true;
        else if(num[i] == '1' && passedZero) {
            passedZero = false;
            totalY ++;
        }
    }
    if(passedZero) {
        totalY ++;
    }

    if(totalY == 0)
        cout << 0;
    else {
        ll totalAns = (totalY-1)*min(x,y)+y;
        cout << totalAns;
    }
    return 0;
}