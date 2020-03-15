#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    map<int, bool> arr;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[x] = true;
    }
    
    if(arr.size() > 3)
        cout << "NO\n";
    else if(arr.size() == 2 || arr.size() == 1) {
        cout << "YES\n";
    } else {
        auto it = arr.begin();
        int one = it++->first;
        int two = it++->first;
        int three = it++->first;
        if(two-one == three-two)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}