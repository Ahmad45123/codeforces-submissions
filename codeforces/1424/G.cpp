#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    
    vector<pair<int, bool>> tmp;
    for(pair<int, int> x : arr) {
        tmp.push_back({x.first, true});
        tmp.push_back({x.second, false});
    }

    sort(tmp.begin(), tmp.end(), comp);

    int mxPeople = 0, year = 0;
    int curPeople = 0;
    for(int i = 0; i < tmp.size(); i++) {
        if(tmp[i].second) {
            curPeople ++;
            if(curPeople > mxPeople) {
                mxPeople = curPeople;
                year = tmp[i].first;
            }
        } else {
            curPeople --;
        }
    }

    cout << year << " " << mxPeople << "\n";

    return 0;
}