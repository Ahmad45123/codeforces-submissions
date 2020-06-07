#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> arr[i][j];
        
        int turn  = 0;
        //int stillLoop = true;

        while(true) {
            bool foundOne = false;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(arr[i][j] == 1)
                        continue;
                    bool good = true;
                    for(int x = 0; x < n; x++) {
                        if(arr[x][j] == 1) {
                            good = false;
                            break;
                        }
                    }
                    for(int x = 0; x < m; x++) {
                        if(arr[i][x] == 1) {
                            good = false;
                            break;
                        }
                    }

                    if(good) {
                        arr[i][j] = 1;
                        foundOne = true;
                        break;
                    }
                }
                if(foundOne)
                    break;
            }

            if(!foundOne)
                break;

            turn = !turn;
        }

        cout << (turn % 2 == 0 ? "Vivek\n" : "Ashish\n");
    }
    
    return 0;
}