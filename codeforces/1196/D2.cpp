#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q; cin >> q;
    while(q--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<short> arr;
        for(char c : s) {
            if(c == 'R')
                arr.push_back(0);
            else if(c == 'G')
                arr.push_back(1);
            else
                arr.push_back(2);
        }
        
        vector<short> A;
        vector<short> B;
        vector<short> C;
        A.push_back(0);
        B.push_back(1);
        C.push_back(2);
        for(int i = 1; i < n; i++) {
            A.push_back((A[A.size()-1]+1)%3);
            B.push_back((B[B.size()-1]+1)%3);
            C.push_back((C[C.size()-1]+1)%3);
        }
        int ansA = 0;
        int ansB = 0;
        int ansC = 0;
        for(int i = 0; i < k; i++) {
            if(arr[i] != A[i]) {
                ansA++;
            }
            if(arr[i] != B[i]) {
                ansB++;
            }
            if(arr[i] != C[i]) {
                ansC++;
            }
        }
        int ans = min({ansA, ansB, ansC});
        for(int i = k; i < n; i++) {
            if(arr[i-k] != A[i-k]) {
                ansA--;
            }
            if(arr[i-k] != B[i-k]) {
                ansB--;
            }
            if(arr[i-k] != C[i-k]) {
                ansC--;
            }

            if(arr[i] != A[i]) {
                ansA++;
            }
            if(arr[i] != B[i]) {
                ansB++;
            }
            if(arr[i] != C[i]) {
                ansC++;
            }
            ans = min({ans, ansA, ansB, ansC});
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}