#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
typedef long long ll;

int n, k, q;
vector<vector<ll>> dp;

int fill(int i, int rem) {
    if(i < 0 || i >= n) return 0;
    if(~dp[i][rem]) { 
        return dp[i][rem];
    }
    if(rem == 0) {
        return dp[i][rem] = 1;
    }
    int toAdd = (fill(i-1, rem-1)%M + fill(i+1, rem-1)%M)%M;
    return dp[i][rem] = toAdd;
}

struct node {
    ll sum;
};
struct segtree {
    int size;
    vector<node> tree;
 
    node merge(node a, node b) {
        return {
            (a.sum + b.sum)%M
        };
    }
 
    node single(ll v) {
        return {v%M};
    }
 
    node NEUTRAL_ELEMENT = {0};
 
    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2*size);
    }
 
    void build(vector<ll> &a, int x, int lx, int rx) {
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
    void build(vector<ll> &a) {
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
    
    cin >> n >> k >> q;
    dp = vector<vector<ll>>(n, vector<ll>(k+1, -1));
    vector<ll> freqs(n, 0);
    for(int i = 0; i < n; i++)
        fill(i, k);

    for(int i = 0; i < n; i++) {
        ll sum = 0;
        for(int j = 0; j <= k; j++) {
            sum += ((dp[i][j]%M)*(dp[i][k-j]%M))%M;
            sum %= M;
        }
        freqs[i] = sum%M;
    }

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i]; arr[i] %= M;
        arr[i] *= freqs[i];
        arr[i] %= M;
    }
    
    segtree tree;
    tree.init(n);
    tree.build(arr);
    while(q--) {
        int i, x; cin >> i >> x;
        tree.set(i-1, ((x%M)*freqs[i-1])%M);
        cout << tree.eval(0, n).sum%M << "\n";
    }

    return 0;
}