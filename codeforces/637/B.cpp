#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    reverse(arr.begin(), arr.end());

    unordered_map<string, bool> vis;
    for(int i = 0; i < n; i++) {
        if(!vis[arr[i]]) {
            cout << arr[i] << '\n';
            vis[arr[i]] = true;
        }
    }
    
    return 0;
}