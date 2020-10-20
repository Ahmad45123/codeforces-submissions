#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    if(n % 2 == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<int> left;
        vector<int> right;
        left.push_back(1);
        bool flag = false;
        for(int i = 2; i < 2*n; i += 2) {
            if(!flag)
                right.push_back(i), right.push_back(i+1);
            else
                left.push_back(i), left.push_back(i+1);
            flag = !flag;
        }
        right.push_back(2*n);
        for(int x : left)
            cout << x << " ";
        for(int x : right)
            cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}