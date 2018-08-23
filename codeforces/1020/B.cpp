#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int n;
bool vis[1001];
vector<int> arr;

int solve(int cur) {
    if(vis[cur])
        return cur;
    vis[cur] = true;

    return solve(arr[cur-1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    arr = vector<int>(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 1; i <= n; i++) {
        memset(vis, false, sizeof vis);
        cout << solve(i) << " ";
    }
    
    return 0;
}