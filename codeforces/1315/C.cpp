#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        vector<bool> fnd(2*n+1);
        for(int &x : arr) {
            cin >> x;
            fnd[x] = true;
        }
        
        vector<int> toAdd;
        for(int i = 1; i <= 2*n; i++) {
            if(!fnd[i])
                toAdd.push_back(i);
        }

        if(toAdd.size() != n) {
            cout << "-1\n";
            continue;
        }

        sort(toAdd.begin(), toAdd.end());
        vector<int> ans;
    
        for(int i = 0; i < n; i++) {
            ans.push_back(arr[i]);
            auto it = upper_bound(toAdd.begin(), toAdd.end(), arr[i]);
            if(it == toAdd.end()) {
                break;
            }
            ans.push_back(*it);
            toAdd.erase(it);
        }

        if(ans.size() == 2*n) {
            for(int x : ans)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}