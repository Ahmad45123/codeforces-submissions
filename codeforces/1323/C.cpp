#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    stack<char> s;
    int ans = 0;
    while(n--) {
        char x; cin >> x;
        if(s.size() == 0) {
            s.push(x);
            continue;
        }
        if(s.top() == x) {
            s.push(x);
        } else {
            if(s.top() == '(' && x == ')') {
                s.pop();
            } else {
                //Also pop but add 2 to result.
                s.pop();
                ans += 2;
            }
        }
    }

    if(s.size() > 0)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
    
    return 0;
}