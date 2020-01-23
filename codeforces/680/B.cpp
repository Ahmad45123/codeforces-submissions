#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, a; cin >> n >> a;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int l = a-1, r = a-1;
    int ans = 0;
    while(l >= 0 || r < n) {
        if(l >= 0 && r < n && arr[l] == 1 && arr[r] == 1) {
            ans += 1;
            if(l != r) ans += 1;
        }
        else if(l < 0 && r < n && arr[r] == 1)
            ans += 1;
        else if(r >= n && l >= 0 && arr[l] == 1)
            ans += 1;
        
        l--;
        r++;
    }
    
    cout << ans << "\n";
    return 0;
}