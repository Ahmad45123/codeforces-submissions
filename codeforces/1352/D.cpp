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
        for(auto &x : arr)
            cin >> x;
        
        int alice = 0;
        int prevAlice = 0;
        int prevBob = 0;
        int bob = 0;
        int turns = 0;

        bool turn = true;
        int i = 0, j = n-1;
        while(i <= j) {
            turns ++;
            if(turn) {
                // alice
                while(prevAlice <= prevBob && i <= j) {
                    alice += arr[i];
                    prevAlice += arr[i];
                    i ++;
                }
                prevBob = 0;
            } else {
                // bob
                while(prevBob <= prevAlice && i <= j) {
                    bob += arr[j];
                    prevBob += arr[j];
                    j --;
                }
                prevAlice = 0;
            }
            turn = !turn;
        }

        cout << turns << " " << alice << " " << bob << "\n";
    }
    
    return 0;
}