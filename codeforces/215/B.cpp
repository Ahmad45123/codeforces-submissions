#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> x(n);
    for(int &i : x)
        cin >> i;
    int m; cin >> m;
    vector<int> y(m);
    for(int &i : y)
        cin >> i;
    int k; cin >> k;
    vector<int> z(k);
    for(int &i : z)
        cin >> i;
    int a, b; cin >> a >> b;

    int maxr1 = *max_element(x.begin(), x.end());
    int maxro1 = *max_element(y.begin(), y.end());
    int minro2 = *min_element(z.begin(), z.end());
    
    cout << fixed << setprecision(6) << maxr1*sqrt((b*maxro1*1.0)/(b*maxro1*1.0+a*minro2*1.0)) << "\n";

    /*double r2 = 0;
    for(int i : y)
        for(int j : z) {
            r2 = max(r2, maxr1*sqrt((b*i*1.0)/(b*i*1.0+a*j*1.0)));
        }
    
    cout << fixed << setprecision(6) << r2 << "\n";*/
    return 0;
}