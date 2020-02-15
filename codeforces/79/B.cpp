#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m, k, t; cin >> n >> m >> k >> t;
    vector<pair<int, int>> arr(k);
    
    for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }
    
    while (t--)
    {
        int i, j; cin >> i >> j;

        int ans = m*(i-1)+j;
        for(int z = 0; z < k; z++) {
            if(arr[z].first == i && arr[z].second == j)
            {
                ans = -1;
                break;
            }
            else if(arr[z].first < i || (arr[z].first == i && arr[z].second < j))
                ans--;
        }

        if(ans == -1) {
            cout << "Waste\n";
        } else {
            ans %= 3;
            if(ans == 0)
                cout << "Grapes\n";
            else if(ans == 1)
                cout << "Carrots\n";
            else if(ans == 2)
                cout << "Kiwis\n";
        }
    }

    return 0;
}