#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m, k; cin >> n >> m >> k;
        int cardsPerPlayer = n/k;
        if(m <= cardsPerPlayer)
            cout << m << "\n";
        else {
            int remCards = m-cardsPerPlayer;
            int cardsDist = ceil(remCards*1.0/(k-1)*1.0);
            cout << cardsPerPlayer-cardsDist << "\n";
        }
    }
    
    return 0;
}