#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> arr;

int countZeros(int i, int j) {
    int zeros = 0;
    if(i+1 < n) {
        if(arr[i+1][j] == 0)
            zeros ++;
    }
    if(j+1 < m) {
        if(arr[i][j+1] == 0)
            zeros ++;
    }
    if(i-1 >= 0) {
        if(arr[i-1][j] == 0)
            zeros ++;
    }
    if(j-1 >= 0) {
        if(arr[i][j-1] == 0)
            zeros ++;
    }
    return zeros;
}

int countNonZeros(int i, int j) {
    int zeros = 0;
    if(i+1 < n) {
        if(arr[i+1][j] != 0)
            zeros ++;
    }
    if(j+1 < m) {
        if(arr[i][j+1] != 0)
            zeros ++;
    }
    if(i-1 >= 0) {
        if(arr[i-1][j] != 0)
            zeros ++;
    }
    if(j-1 >= 0) {
        if(arr[i][j-1] != 0)
            zeros ++;
    }
    return zeros;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        arr = vector<vector<int>>(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) 
                cin >> arr[i][j];

        bool bad = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == 0)
                    continue;
                else if(arr[i][j] > 4) {
                    bad = true;
                } else {
                    int nonZeros = countNonZeros(i, j);
                    int zeros = countZeros(i, j);
                    if(arr[i][j]-nonZeros > zeros)
                        bad = true;
                }
            }
        }
        
        if(bad) {
            cout << "NO\n";
            continue;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                arr[i][j] = countZeros(i, j)+countNonZeros(i, j);
            }

        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
    }
    
    return 0;
}