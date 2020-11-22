#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        vector<int> b(k);
        for(int &x : a)
            cin >> x;
        for(int &x : b)
            cin >> x;
        
        map<int, list<int>::iterator> its;
        map<int, bool> usedFromA;
        map<int, bool> neededInB;
        for(int v : b)
            neededInB[v] = true;
        list<int> lst;
        auto currIt = lst.insert(lst.begin(), a[n-1]);
        its[a[n-1]] = currIt;
        for(int i = n-2; i >= 0; i--) {
            currIt = lst.insert(currIt, a[i]);
            its[a[i]] = currIt;
        }

        ll ans = 1;

        for(int v : b) {
            if(its.find(v) == its.end() || usedFromA[v]) {
                ans = 0;
                break;
            }

            auto elemInA = its[v];
            int cntRemoveable = 0;
            auto elemtAfter = elemInA;
            elemtAfter ++;
            if(elemtAfter != lst.end() && !neededInB[*elemtAfter]) {
                cntRemoveable ++;
                usedFromA[*elemtAfter] = true;
                lst.erase(elemtAfter);
            }
            auto elemtBefore = elemInA;
            elemtBefore --;
            if(elemInA != lst.begin() && !neededInB[*elemtBefore]) {
                cntRemoveable ++;
                usedFromA[*elemtBefore] = true;
                lst.erase(elemtBefore);
            }

            ans *= cntRemoveable;
            ans %= 998244353;

            neededInB[*elemInA] = false;
        }

        cout << ans << "\n";
    }
    
    return 0;
}