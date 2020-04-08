#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<string> ans;

        if(n == 2 && m % 2 != 0) {
            for(int i = 0; i < n; i++) {
            string tmp = "";
            char cur = 'B';
            for(int j = 0; j < m; j++) {
                if(i == n-1 && (j == 0 || j == 1)) {
                    tmp += 'B';
                    cur = 'W';
                } else {
                tmp += cur;
                cur = (cur == 'B' ? 'W' : 'B');
                }
            }
                
            ans.push_back(tmp);
            }
        } else if(m % 2 == 0) {
            for(int i = 0; i < n; i++) {
            string tmp = "";
            char cur = 'B';
            for(int j = 0; j < m; j++) {
                if(i == n-1 && (j == 0 || j == 1)) {
                    tmp += 'B';
                } else {
                tmp += cur;
                cur = (cur == 'B' ? 'W' : 'B');
                }
            }
                
            ans.push_back(tmp);
        }
        } else
        for(int i = 0; i < n; i++) {
            string tmp = "";
            char cur = 'B';
            for(int j = 0; j < m; j++) {
                if(j == m-1) {
                    if(i >= n-2) 
                        cur = 'B';
                    else
                        cur = 'W';
                }
                tmp += cur;
                cur = (cur == 'B' ? 'W' : 'B');
            }
                
            ans.push_back(tmp);
        }

        for(auto &s : ans) {
            cout << s << "\n";
        }
    }
    
    return 0;
}