#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k, d; cin >> n >> k >> d;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        
        map<int, int> tmp;
        for(int i = 0; i < d; i++)
            tmp[arr[i]] ++;

        int ans = tmp.size();
        for(int i = d; i < n; i++) {
            tmp[arr[i-d]] --;
            tmp[arr[i]] ++;
            if(tmp[arr[i-d]] == 0)  tmp.erase(arr[i-d]);
            ans = min(ans, (int)tmp.size());
        }

        cout << ans << "\n";
    }
    
    return 0;
}