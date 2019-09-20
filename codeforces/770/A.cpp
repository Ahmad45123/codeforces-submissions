#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k; cin >> n >> k;
    string ans;

    char cur = 'a';
    for(int i = 0; i < k; i++) {
        ans.push_back(cur);
        cur++;
    }

    bool flag = true;
    for(int i = k; i < n; i++) {
        if(flag)
            ans.push_back('a');
        else
            ans.push_back('b');
        flag = !flag;
    }

    cout << ans << "\n";

    return 0;
}