#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct node {
    int xr;
};
struct segtree {
    int size;
    vector<node> tree;
 
    node merge(node a, node b) {
        return {
            a.xr^b.xr
        };
    }
 
    node single(int v) {
        return {v};
    }
 
    node NEUTRAL_ELEMENT = {0};
 
    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2*size);
    }
 
    void build(vector<int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < a.size()) {
                tree[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }
 
    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = single(v);
            return;
        }
        int m = (lx+rx)/2;
        if(i < m) {
            set(i, v, 2*x+1, lx, m);
        } else {
            set(i, v, 2*x+2, m, rx);
        }
        
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
 
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
 
    node eval(int l, int r, int x, int lx, int rx) {
        if(lx >= r || rx <= l) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r) return tree[x];
        int m = (lx+rx)/2;
        return merge(eval(l, r, 2*x+1, lx, m), eval(l, r, 2*x+2, m, rx));
    }
 
    node eval(int l, int r) {
        return eval(l, r, 0, 0, size);
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    segtree seg;
    seg.init(n);
    seg.build(arr);

    ll b[n + 5];
    for (ll i = 0; i < n; i++) {
        b[i] = 30 -__builtin_clz(arr[i]);
    }

    for (ll i = 0; i < n - 3; i++) {
        if (b[i] == b[i + 1] && b[i + 1] == b[i + 2]) {
            cout << "1\n";
            return 0;
        }
    }

    int ans = 1e9;

    for(int l = 0; l < n; l ++) {
        for(int r = l + 2; r < n; r ++) {
            for(int m = l; m < r; m++) {
                if(seg.eval(l, m+1).xr > seg.eval(m+1, r+1).xr) {
                    ans = min(ans, r-l-1);
                }
            }
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << "\n";
    
    return 0;
}