#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("inp.txt", "r", stdin);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> arr[i][j];
        
       for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
				if((i+j) % 2 != arr[i][j] % 2)
					arr[i][j] ++;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
    }
    
    return 0;
}