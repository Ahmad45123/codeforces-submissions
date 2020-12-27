#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q; cin >> q;
    while(q--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        
        vector<int> lenses;
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            tmp ++;
            if(arr[i] % 2 != 0) {
                lenses.push_back(tmp);
                tmp = 0;
            }
        }
        if(lenses.size() > 0) lenses[lenses.size()-1] += tmp;

        if(lenses.size() < k) {
            cout << "NO\n";
            continue;
        } else if(lenses.size() == k) {
            cout << "YES\n";
            cout << lenses[0] << " ";
            for(int i = 1; i < lenses.size(); i++) {
                lenses[i] += lenses[i-1];
                cout << lenses[i] << " ";
            }
            cout << "\n";
        } else {
            while(lenses.size() > k) {
                if(lenses.size() < 3)
                    break;
                
                lenses[lenses.size()-3] += lenses[lenses.size()-1] + lenses[lenses.size()-2];
                lenses.pop_back();
                lenses.pop_back();
            }
            if(lenses.size() == k) {
                cout << "YES\n";
                cout << lenses[0] << " ";
                for(int i = 1; i < lenses.size(); i++) {
                    lenses[i] += lenses[i-1];
                    cout << lenses[i] << " ";
                }
                cout << "\n";
            } else
                cout << "NO\n";
        }
    }
    
    return 0;
}