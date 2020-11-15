#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    vector<vector<int>> L(n + 1, vector<int>(m + 1));  
    int ans = 0;
    for (int i = 0; i <= n; i++)  
    {  
        for (int j = 0; j <= m; j++)  
        {  
            if (i == 0 || j == 0)  
                L[i][j] = 0;  
        
            else if (a[i - 1] == b[j - 1])  
                L[i][j] = max(max(L[i][j], 2), L[i - 1][j - 1] + 2);
        
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]) - 1;

            ans = max(ans, L[i][j]);
        }  
    }

    cout << ans << "\n";
    
    return 0;
}