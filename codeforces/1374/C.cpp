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
        stack<char> stck;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(')
                stck.push('(');
            else if(s[i] == ')') {
                if(stck.size() > 0 && stck.top() == '(')
                    stck.pop();
                else
                    stck.push(')');
            }
        }
        cout << stck.size()/2 << "\n";
    }
    
    return 0;
}