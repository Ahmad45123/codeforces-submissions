#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        string bestAns = "";
        int ansInt = -1;
        for(int i = 0; i < n; i++) {
            string left = s.substr(0, i);
            string right = s.substr(i, n-i);
            if(right.size() % 2 != 0) {
                reverse(left.begin(), left.end());
            }
            string tmp = right + left;
            int ans = i+1;
            if(bestAns == "" || tmp < bestAns || (tmp == bestAns && ans < ansInt)) {
                bestAns = tmp;
                ansInt = ans;
            }
        }

        cout << bestAns << "\n" << ansInt << "\n";
    }
    
    return 0;
}