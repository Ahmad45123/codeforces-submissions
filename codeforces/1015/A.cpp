#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n, m; cin >> n >> m;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++) {
        int s,e; cin >> s >> e;
        arr[i] = {s,e};
    }

    vector<int> ans;
    for(int i = 1; i <= m; i++) {
        bool isFound = true;
        for(int j = 0; j < n; j++) {
            if(i >= arr[j].first && i <= arr[j].second) {
                isFound = false;
                break;
            }
        }
        if(isFound)
            ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}