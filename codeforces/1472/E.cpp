#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct person {
    int h;
    int w;
    int idx;
};

bool compare(person a, person b) {
    if(a.h == b.h) {
        return a.w < b.w;
    }
    return a.h < b.h;
}

void solve(vector<person> arr, vector<int> &ans) {
    sort(arr.begin(), arr.end(), compare);
    vector<pair<int, int>> mnPrefix(arr.size());
    mnPrefix[0] = {arr[0].w, arr[0].idx};
    for(int i = 1; i < arr.size(); i++) {
        mnPrefix[i] = mnPrefix[i-1];
        if(arr[i].w < mnPrefix[i].first) {
            mnPrefix[i].first = arr[i].w;
            mnPrefix[i].second = arr[i].idx;
        }
    }

    for(int i = 0; i < arr.size(); i++) {
        if(ans[arr[i].idx] == -1) {
            auto it = lower_bound(arr.begin(), arr.end(), arr[i].h, [](person a, int b) {
                return a.h < b;
            });
            if(it == arr.begin()) continue;
            it --;
            int j = it-arr.begin();
            if(mnPrefix[j].first < arr[i].w) {
                ans[arr[i].idx] = mnPrefix[j].second;
            }
        }
    }
    
    for(int i = 0; i < arr.size(); i++) {
        if(ans[arr[i].idx] == -1) {
            auto it = lower_bound(arr.begin(), arr.end(), arr[i].w, [](person a, int b) {
                return a.h < b;
            });
            if(it == arr.begin()) continue;
            it --;
            int j = it-arr.begin();
            if(mnPrefix[j].first < arr[i].h) {
                ans[arr[i].idx] = mnPrefix[j].second;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<person> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i].h >> arr[i].w;
            arr[i].idx = i;
        }
        
        vector<int> res(n, -1);
        solve(arr, res);
    
        for(int x : res)
            cout << (x == -1 ? -1 : x+1) << " ";
        cout << "\n";
    }
    
    cerr << "Run time: " << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}