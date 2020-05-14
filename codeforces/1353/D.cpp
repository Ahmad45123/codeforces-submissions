#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Compare
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

int getMid(int l, int r) {
    if(r-l+1 % 2 == 0)
        return (l+r-1)/2;
    else
        return (l+r)/2;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> ans(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q; // size, left
        q.push({n, 1});
        int cur = 1;
        while(!q.empty()) {
            int l = q.top().second;
            int r = q.top().first+q.top().second-1;
            q.pop();
            int mid = getMid(l, r);
            ans[mid-1] = cur++;
            if(l == r)
                continue;

            int l1 = l;
            int r1 = mid-1;
            int l2 = mid+1;
            int r2 = r;

            if(l1 <= r1) {
                q.push({r1-l1+1, l1});
            }
            if(l2 <= r2) {
                q.push({r2-l2+1, l2});
            }
        }

        for(auto &x : ans)
            cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}