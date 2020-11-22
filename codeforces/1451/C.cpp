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
        string a, b; cin >> a >> b;

        if(*max_element(a.begin(), a.end()) > *max_element(b.begin(), b.end())) {
            cout << "No\n";
            continue;
        }

        vector<int> cntA(26);
        vector<int> cntB(26);
        for(char c : a)
            cntA[c-'a'] ++;
        for(char c : b)
            cntB[c-'a'] ++;

        bool flag = true;
        for(int i = 0; i < 26; i++) {
            if(i > 0)
                cntA[i] += cntA[i-1];
            if(cntA[i] < cntB[i]) {
                flag = false;
                break;
            }
            cntA[i] -= cntB[i];
            if(cntA[i] % k != 0) {
                flag = false;
                break;
            } 
        }

        cout << (flag ? "Yes\n" : "No\n");
    }
    
    return 0;
}