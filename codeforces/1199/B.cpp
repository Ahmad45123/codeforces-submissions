#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    double H, L; cin >> H >> L;
    cout << fixed << setprecision(6) << (pow(L, 2)-pow(H, 2))/(2*H) << "\n";
    
    return 0;
}