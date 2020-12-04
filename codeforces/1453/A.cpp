#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> arr1(n);
        vector<int> arr2(m);
        for(int &x : arr1)
            cin >> x;
        
        for(int &x : arr2)
            cin >> x;
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(arr1[i] == arr2[j])
                    ans ++;
        
        cout << ans << "\n";
    }
    
    return 0;
}