#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

double C(int a, int b) {
    double x = 1;
    double bfact = 1;
    for(int i = a; i > a-b; i--)
        x *= i;
    for(int i = b; i > 1; i--)
        bfact *= i;
    return x/bfact;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string s; cin >> s;
    string t; cin >> t;
    int n = s.size();

    int plus = 0, minus = 0;
    int quest = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '+')
            plus++;
        else
            minus++;
        if(t[i] == '+')
            plus--;
        else if(t[i] == '-')
            minus--;
        else
            quest++;
    }

    if(plus == 0 && minus == 0) {
        cout << 1.0 << "\n";
        return 0;
    } else if(plus < 0 || minus < 0 || quest == 0 || quest != plus+minus) {
        cout << 0.0 << "\n";
        return 0;
    }

    cout << fixed << setprecision(9) << (C(quest, plus)/pow(2, quest)) << "\n";

    return 0;
}