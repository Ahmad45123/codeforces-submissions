#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

bool comp (int a, int b)
{
    return a > b;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<int> arr;
    vector<int> counts;
    unordered_map<int, int> um;
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        um[t]++;
        if(um[t] == 1)
            arr.push_back(t);
    }
    for(int i = 0; i < arr.size(); i++) {
        counts.push_back(um[arr[i]]);
    }
    sort(counts.begin(), counts.end(), comp);


    int days = 0;
    while(true) {
        int curElm = 0;
        vector<int> tmp = counts;
        for(int i = 0; i < n; i++) {
            if(tmp[curElm] >= days) {
                tmp[curElm] -= days;
            }
            else {
                curElm++;
                i--;
                if(curElm >= tmp.size()) {
                    curElm = -1;
                    break;
                }
            }
        }
        if(curElm == -1)
            break;
        days ++;
    }
    
    cout << days-1;

    return 0;
}