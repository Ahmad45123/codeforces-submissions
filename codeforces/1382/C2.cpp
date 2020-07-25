#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(vector<int> &ans, string &x) {
    char curPrefix = x[0];
    for(int i = 0; i < x.size(); i++) {
        if(x[i] != curPrefix) {
            ans.push_back(i);
            curPrefix = x[i];
        }
    }
    if(curPrefix == '1')
        ans.push_back(x.size());
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        vector<int> prt1;
        vector<int> prt2;
        solve(prt1, a);
        solve(prt2, b);
        reverse(prt2.begin(), prt2.end());
        cout << prt1.size()+prt2.size() << " ";
        for(int i = 0; i < prt1.size(); i++)
            cout << prt1[i] << " ";
        for(int i = 0; i < prt2.size(); i++)
            cout << prt2[i] << " ";
        cout << "\n";
    }
    
    return 0;
}