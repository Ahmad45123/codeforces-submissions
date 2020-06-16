#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(2*n);
        for(int i = 0; i < 2*n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        cout << arr[n]-arr[n-1] << "\n";
    }
    
    return 0;
}