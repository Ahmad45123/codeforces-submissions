#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int getRelative(int i, int k) {
    int rel = i % k;
    if(k%2 == 0 && rel >= k/2) {
        rel = k-rel-1;
    } else if(rel > k/2) {
        rel = k-rel-1;
    }
    return rel;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int[27]> arr(k);
        vector<char> ans(k);
        for(int i = 0; i < n; i++) {
            int rel = getRelative(i, k);
            arr[rel][s[i]-'a'] ++;
        }

        for(int i = 0; i < k; i++) {
            int maxTillNow = 0;
            char maxIndex = '.';
            for(int j = 0; j < 27; j++) {
                if(arr[i][j] > maxTillNow) {
                    maxTillNow = arr[i][j];
                    maxIndex = 'a'+j;
                }
            }
            ans[i] = maxIndex;
        }

        int ansInt = 0;
        for(int i = 0; i < n; i++) {
            int rel = getRelative(i, k);
            if(s[i] != ans[rel])
                ansInt ++;
        }

        cout << ansInt << "\n";
    }
    return 0;
}