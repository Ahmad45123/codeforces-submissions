#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 131075; // 
ll arr[N];
ll segtree[4*N];

void build(int v, int l, int r, bool mode) {
    if(l == r)
        segtree[v] = arr[l];
    else {
        int mid = (l+r)/2;
        build(v*2, l, mid, !mode);
        build(v*2+1, mid+1, r, !mode);
        if(mode == 0)
            segtree[v] = segtree[v*2]|segtree[v*2+1];
        else
            segtree[v] = segtree[v*2]^segtree[v*2+1];
    }
}

void update(int v, int l, int r, int pos, int val, bool mode) {
    if(l == r) {
        segtree[v] = val;
    } else {
        int mid = (l+r)/2;
        if(pos <= mid) {
            update(v*2, l, mid, pos, val, !mode);
        } else {
            update(v*2+1, mid+1, r, pos, val, !mode);
        }

        if(mode == 0)
            segtree[v] = segtree[v*2]|segtree[v*2+1];
        else
            segtree[v] = segtree[v*2]^segtree[v*2+1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    bool md = (n%2==0 ? 1 : 0);
    n = 1 << n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    build(1, 0, n-1, md);

    for(int i = 0; i < m; i++) {
        ll p, b; cin >> p >> b;
        update(1, 0, n-1, p-1, b, md);
        cout << segtree[1] << "\n";
    }
    
    return 0;
}