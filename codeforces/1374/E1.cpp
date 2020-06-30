#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k; cin >> n >> k;
    priority_queue <int, vector<int>, greater<int>> both;
    priority_queue <int, vector<int>, greater<int>> first;
    priority_queue <int, vector<int>, greater<int>> second;
    while(n--) {
        int t, a, b; cin >> t >> a >> b;
        if(a == 1 && b == 1)
            both.push(t);
        else if(a == 1)
            first.push(t);
        else if(b == 1)
            second.push(t);
    }

    ll ans = 0;

    while(k--) {
        if(first.empty() || second.empty()) {
            if(both.empty()) {
                ans = -1;
                break;
            } else {
                ans += both.top();
                both.pop();
            }
        } else {
            if(both.empty()) {
                ans += first.top()+second.top();
                first.pop();
                second.pop();
            } else {
                if(first.top() + second.top() <= both.top()) {
                    ans += first.top()+second.top();
                    first.pop();
                    second.pop();
                } else {
                    ans += both.top();
                    both.pop();
                }
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}