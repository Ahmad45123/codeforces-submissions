#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &x : arr) {
        cin >> x;
    }

    int nPositive = 0;
    int nNegative = 0;

    for(int i = 0; i < n; i++)
        if(arr[i] > 0)
            nPositive++;
        else if(arr[i] < 0)
            nNegative++;
    
    if(nPositive >= ceil(n*1.0/2.0))
        cout << 1 << "\n";
    else if(nNegative >= ceil(n*1.0/2.0))
        cout << -1 << "\n";
    else
        cout << 0 << "\n";

    return 0;
}