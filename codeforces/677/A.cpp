#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);

    int n, t; cin >> n >> t;
    int r = 0;
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        if(v > t)
            r += 2;
        else
            r ++;
        
    }

    cout << r << '\n';
    return 0;
}