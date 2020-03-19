#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    int mx = arr[0];
    for(int i = 1; i < n; i++) {
        arr[i] += mx;
        mx = max(mx, arr[i]);
    }
    for(int i : arr)
        cout << i << " ";
    
    return 0;
}