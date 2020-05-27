#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    int arr[101] = {};
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        arr[x] = i;
    }
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}