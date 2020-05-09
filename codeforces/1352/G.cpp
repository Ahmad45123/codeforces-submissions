    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;

    int main()
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
        int t; cin >> t;
        while(t--) {
            int n; cin >> n;

            if(n < 4) {
                cout << "-1\n";
                continue;
            }

            vector<int> even;
            vector<int> odd;
            for(int i = 1; i <= n; i ++) {
                if(i == 4) continue;
                if(i % 2 == 0)
                    even.push_back(i);
                else    
                    odd.push_back(i);
            }
            
            reverse(odd.begin(), odd.end());

            for(int i = 0; i < odd.size(); i++) {
                cout << odd[i] << " ";
            }
            cout << 4 << " ";
            for(int i = 0; i < even.size(); i++) {
                cout << even[i] << " ";
            }
            cout << "\n";
        }
        
        return 0;
    }