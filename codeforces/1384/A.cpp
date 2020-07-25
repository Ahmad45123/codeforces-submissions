#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char c = 'a';
char nextChar() {
    c++;
    if(c == 'z'+1)
        c = 'a';
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        int mx = 0, mxIdx = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] > mx) {
                mx = arr[i];
                mxIdx = i;
            }
        }

        
        vector<string> ans;

        string tmp = "";

        if(mx == 0) {
            for(int i = 0; i < n+1; i++) {
                cout << c << "\n";
                c ++;
                if(c == 'z')
                    c = 'a';
            }
            continue;
        }
        
        for(int i = 0; i < arr[0]; i++)
            tmp += c;
        if(arr[0] == 0) {
            tmp = c;
        }
        ans.push_back(tmp);
        if(arr[0] != 0)
            ans.push_back(tmp);
        else {
            string x = ""; x = nextChar();
            ans.push_back(x);
        }

        for(int i = 1; i < n; i++) {
            int prev = ans.size()-1;
            int prevSize = ans[prev].size();

            if(arr[i] == 0) {
                string x = ""; x = nextChar();
                ans.push_back(x);
                continue;
            }

            if(arr[i] >= prevSize) {
                if(arr[i] > prevSize)
                    nextChar();
                while(ans[prev].size() < arr[i]) {
                    ans[prev] += c;
                }
                ans.push_back(ans[prev]);
            } else {
                tmp = "";
                for(int j = 0; j < arr[i]; j++)
                    tmp += ans[prev][j];
                ans.push_back(tmp);
            }
        }

        while(ans.size() != n+1)
            c ++;

        for(auto &x : ans)
            cout << x << "\n";
    }
    
    return 0;
}