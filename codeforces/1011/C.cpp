#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

#define EPS 0.000001

int n; double m;
vector<int> lifts;
vector<int> lands;

bool can(double fuel) {
    for(int i = 0; i < n; i++) {
        fuel -= (fuel+m)/lifts[i];
        if(i+1 >= n)
            fuel -= (fuel+m)/lands[0];
        else
            fuel -= (fuel+m)/lands[i+1];

        if(fuel < 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    lifts = vector<int>(n);
    lands = vector<int>(n);
    for(int i = 0; i < n; i++)
        cin >> lifts[i];
    for(int i = 0; i < n; i++)
        cin >> lands[i];

    double low = 0; double high = 1e10;
    bool hasAns = false;
    while(high-low > EPS) {
        double mid = (low+high) / 2.0;
        
        if(can(mid)) {
            hasAns = true;
            high = mid;
        }
        else {
            low = mid;
        }
    }

    if(!hasAns)
        cout << -1;
    else
        cout << setprecision(12) << low;
    return 0;
}