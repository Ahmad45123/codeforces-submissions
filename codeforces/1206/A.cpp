#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<bool> pass(205, false);
    vector<int> A(n);
    for(int &x : A) {
        cin >> x;
        pass[x] = true;
    }
    int m; cin >> m;
    vector<int> B(m);
    for(int &x : B) {
        cin >> x;
        pass[x] = true;
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(!pass[A[i]+B[j]]) {
                cout << A[i] << " " << B[j] << "\n";
                return 0;
            }
        }
    
    return 0;
}