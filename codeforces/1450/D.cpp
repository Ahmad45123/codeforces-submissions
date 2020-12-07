#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    ll min;
};
struct segtree {
    int size;
    vector<node> tree;
 
    node merge(node a, node b) {
        return {
            min(a.min, b.min)
        };
    }
 
    node single(ll v) {
        return {v};
    }
 
    node NEUTRAL_ELEMENT = {(ll)1e9};
 
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
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        
        segtree tree;
        tree.init(n);
        tree.build(arr);

        vector<bool> good(n+1);

        int l = 0, r = n-1;
        for(int i = 1; i <= n; i++) {
            bool dne = false;
            if(arr[l] == i) {
                dne = true;
                l ++;
            }
            else if(arr[r] == i) {
                dne = true;
                r --;
            }
            
            if(dne && tree.eval(l, r+1).min == i+1) {
                good[n-i] = true;
            }

            if(!good[n-i]) break;
        }

        if(tree.eval(0, n).min == 1)
            good[n] = true;
        else
            good[n] = false;
        
        sort(arr.begin(), arr.end());
        bool tmp = true;
        for(int i = 1; i < n; i++)
            if(arr[i] != arr[i-1]+1) tmp = false;
        if(tmp)
            good[1] = true;
        else
            good[1] = false;
    
        for(int i = 1; i <= n; i++)
            cout << good[i];
        cout << "\n";
    }
    
    return 0;
}