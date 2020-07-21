#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        
        n--;
        if(n == 0) {
            cout << "First\n";
            continue;
        }

        bool turn = 1;

        for(int i = 0; i < n; i++) {
            if(arr[i] != 1) {
                int ones = 0;
                int j = i+1;
                while(j < n && arr[j] == 1) {
                    ones ++;
                    j ++;
                }
                if(ones % 2 != 0) {
                    turn != turn;
                }
                i = j-1;
            } else {
                turn = !turn;
            }
        }

        cout << (turn ? "First\n" : "Second\n");
    }
    
    return 0;
}