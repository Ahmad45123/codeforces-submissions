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
        for(int &x : arr)
            cin >> x;
        
        bool same = true;
        for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i-1])
                same = false;
        }
        if(same) {
            cout << "NO\n";
            continue;
        }

        vector<bool> used(n);
        vector<pair<int, int>> edges;
        
        for(int i = 0; i < n; i++) { 
            if(!used[i]) {
                used[i] = true;
                for(int j = 0; j < n; j++) {
                    if(arr[i] != arr[j]) {
                        edges.push_back({i+1, j+1});
                        used[j] = true;
                        break;
                    }
                    // if(edges.size() == n-1) break;
                }
            }
            // if(edges.size() == n-1) break;
        }

        cout << "YES\n";
        for(auto x : edges) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    
    return 0;
}