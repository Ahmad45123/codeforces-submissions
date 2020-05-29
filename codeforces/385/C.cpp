#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> counts(1e7+1);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        counts[x] ++;
    }

    vector<int> arr(1e7+1, 0);
    vector<bool> mark(1e7+1, false);

    mark[0] = true;
    mark[1] = true;
    for(int i = 2; i <= 1e7; i++) {
        if(!mark[i]) {
            int cnt = 0;
            for(int tmp = i; tmp <= 1e7; tmp += i) {
                mark[tmp] = true;
                cnt += counts[tmp];
            }
            arr[i] = cnt;
        }
    }

    for(int i = 1; i <= 1e7; i++)
        arr[i] += arr[i-1];

    int m; cin >> m;
    while(m--) {
        int l, r; cin >> l >> r;
        l = min(l, (int)1e7);
        r = min(r, (int)1e7);
        cout << arr[r]-arr[l-1] << "\n";
    }
    
    return 0;
}