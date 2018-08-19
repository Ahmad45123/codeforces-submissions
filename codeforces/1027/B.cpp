#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n, q; cin >> n >> q;
    
    ll npw = pow(n, 2);

    ll numEvenElements;
    ll numOddElements;
    if(n % 2 == 0)
        numEvenElements = numOddElements = n / 2;
    else {
        numEvenElements = (n+1)/2;
        numOddElements = numEvenElements-1;
    }
    
    while(q--) {
        int x, y; cin >> x >> y;
        ll numeven;
        ll numodd;
        x--;
        if(x%2 == 0)
            numeven = numodd = x/2;
        else {
            numeven = (x+1)/2;
            numodd = numeven-1;
        }
        x++;

        if((x+y)%2 == 0) {
            ll a = (numEvenElements*numeven)+(numOddElements*numodd)+ceil(y/2.0f);
            cout << a << endl;
        }
        else {
            swap(numeven, numodd);
            ll a = ceil(npw/2.0f)+(numEvenElements*numeven)+(numOddElements*numodd)+ceil(y/2.0f);
            cout << a << endl;
        }
    }
    return 0;
}