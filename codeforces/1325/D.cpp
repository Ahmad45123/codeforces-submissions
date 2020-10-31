#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll X, S; cin >> X >> S;
    ll A = (S-X)/2;
    ll a = 0, b = 0;

    if(X > S || (X % 2 != S % 2)) {
        cout << "-1\n";
        return 0;
    }

    if(X == S && X == 0) {
        cout << "0\n";
        return 0;
    }

    if(X == S) {
        cout << "1\n" << S << "\n";
        return 0;
    }

    bool bad = false;

    for(ll i = 0; i < 8*sizeof(S); i++) {
        unsigned long long Xi = ((1LL << i) & X);
        unsigned long long Ai = ((1LL << i) & A);
        if(Ai > 0 && Xi == 0) {
            a = (a | (1LL << i));
            b = (b | (1LL << i));
        } else if(Ai == 0 && Xi == 0) {
        } else if(Ai == 0 && Xi > 0) {
            if(a < b) a = (a | (1LL << i));
            else b = (b | (1LL << i));
        } else {
            bad = true;
            break;
        }
    }

    if(bad) {
        cout << "3\n" << X << " " << A << " " << A << "\n";
    } else {
        cout << "2\n" << a << " " << b << "\n";
    }

    return 0;
}