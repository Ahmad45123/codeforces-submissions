#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double getAverage(double h, double c, double x, double y) {
    return (x*h+y*c)/(x+y);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        double h, c, t; cin >> h >> c >> t;

        int x1 = ceil((c-t)/(h+c-2*t));
        int x2 = x1-1;
        double diff1 = abs(t-((h+c)/2));
        double diff2 = x1 <= 0 ? 1e9 : abs(t-getAverage(h, c, x1, x1-1));
        double diff3 = x2 <= 0 ? 1e9 : abs(t-getAverage(h, c, x2, x2-1));
        int idkAns = 1e9;
        if(diff1 <= diff2 && diff1 <= diff3) {
            idkAns = 2;
        }
        if(diff2 <= diff1 && diff2 <= diff3) {
            idkAns = min(idkAns, x1+x1-1);
        }
        if(diff3 <= diff1 && diff3 <= diff2) {
            idkAns = min(idkAns, x2+x2-1);
        }

        if(h == c && c == t)
            idkAns = 1;

        cout << idkAns << "\n";
    }
    
    return 0;
}