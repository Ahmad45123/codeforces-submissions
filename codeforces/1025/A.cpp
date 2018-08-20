    #include <bits/stdc++.h>

    using namespace std;
    #define mp make_pair
    typedef long long int ll;

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n; cin >> n;
        string s; cin >> s;
        map<char, bool> passed;
        
        if(n == 1) {
            cout << "Yes";
            return 0;
        }

        for(int i = 0; i < n; i++) {
            if(passed[s[i]])
            {
                cout << "Yes";
                return 0;
            }
            passed[s[i]] = true;
        }
        
        cout << "No";
        return 0;
    }