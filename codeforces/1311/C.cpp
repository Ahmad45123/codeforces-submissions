#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        vector<int> numRight(m);
        for(int i = 0; i < m; i++)
            cin >> numRight[i];
        
        int numberTimes[27];
        memset(numberTimes, 0, sizeof numberTimes);
        
        sort(numRight.begin(), numRight.end());
        int lastPos = 0;
        for(int i = 0; i < m; i++) {
            int factor = m-i;
            for(int j = lastPos; j < numRight[i]; j++) {
                numberTimes[s[j]-'a'] += factor;
            }
            lastPos = numRight[i];
        }

        for(int i = 0; i < n; i++)
            numberTimes[s[i]-'a'] ++;

        for(int c = 0; c < 26; c++) {
            cout << numberTimes[c] << " ";
        }
        cout << "\n";

    }
    
    return 0;
}