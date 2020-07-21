#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        vector<int> ans;
        while(n > 0 && a[n-1] == b[n-1]) {
            n --;
        }
        
        /*for(int i = 0; i < n; i++) {
            if(b[i] == '1')
                b[i] = '0';
            else if(b[i] == '0')
                b[i] = '1';
        }
        reverse(b.begin(), b.end());*/

        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                ans.push_back(i+1);
                ans.push_back(1);
                ans.push_back(i+1);
            }
        }

        //ans.push_back(n);

        cout << ans.size() << " ";
        for(auto &x : ans)
            cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}