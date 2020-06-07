#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            arr[i] = {x, 0};
        }
        for(int i = 0; i < n; i++) {
            cin >> arr[i].second;
        }

        //If already sorted.
        bool alreadySorted = true;
        bool sameBs = true;
        for(int i = 1; i < n; i++) {
            if(arr[i].first < arr[i-1].first)
                alreadySorted = false;
            if(arr[i].second != arr[i-1].second)
                sameBs = false;
        }
        if(alreadySorted) {
            cout << "Yes\n";
            continue;
        }
        if(sameBs) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";
    }
    
    return 0;
}