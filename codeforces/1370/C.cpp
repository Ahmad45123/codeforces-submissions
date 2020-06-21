#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n;
        if(n == 1) cout << "FastestFinger\n";
        else if(n == 2) cout << "Ashishgup\n";
        else if(n % 2 == 1) {
            cout << "Ashishgup\n";
        } else {
            //n is even.
            int turn = 0;
            for(int i = 2; i <= sqrt(n); i ++) {
                if(n % i == 0 && n / i != 2 && i % 2 != 0) {
                    turn = !turn;
                    break;
                } else if(n % i == 0) {
                    int x = n/i;
                    if(x != i) {
                        if(n / x != 2 && x % 2 != 0) {
                            turn = !turn;   
                            break;
                        }
                    }
                }
            }
            cout << (turn == 0 ? "FastestFinger\n" : "Ashishgup\n");
        }

    }
    
    return 0;
}