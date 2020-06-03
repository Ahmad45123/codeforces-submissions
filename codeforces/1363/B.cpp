#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        vector<int> countOnes(n+2);
        vector<int> countZeros(n+2);
        for(int i = 0; i < n; i++) {
            if(s[i] == '1')
                countOnes[i+1] = 1;
            else
                countZeros[i+1] = 1;
        }
        for(int i = 1; i <= n; i++) {
            countZeros[i] += countZeros[i-1];
            countOnes[i] += countOnes[i-1];
        }

        int bestAns = 1e9;
        for(int i = 1; i <= n; i++) {
            int ans1 = countOnes[i-1]+(countZeros[n]-countZeros[i-1]);
            int ans2 = countZeros[i-1]+(countOnes[n]-countOnes[i-1]);
            bestAns = min(bestAns, min(ans1, ans2));
        }

        cout << bestAns << "\n";
    }
    
    return 0;
}