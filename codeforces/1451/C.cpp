#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve(string a, string b, int n, int k) {
    int s = 0;
    while(a[s] == b[s] && s < n) s++;
    while(s < n) {
        int e = s + k - 1;
        if(e >= n) {
            return false;
        }

        char frst = '1';
        char second = '1';
        for(int i = s; i <= e; i ++) {
            if(frst == '1')
                frst = a[i];
            
            if(second == '1')
                second = b[i];
            
            if(frst != a[i] || second != b[i])
                return false;
        }

        if(frst > second)
            return false;

        s += k;
        while(a[s] == b[s] && s < n) s++;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string a, b; cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b) {
            cout << "Yes\n";
            continue;
        }

        bool flag = true;

        for(int i = 0; i < n; i++) {
            if(a[i] > b[i]) {
                flag = false;
            }
        }

        if(!flag) {
            cout << "No\n";
            continue;
        }

        string newa = "", newb = "";

        map<char, int> mp;
        for(char c : a)
            mp[c] ++;
        
        for(char c : b) {
            if(mp[c] == 0) {
                newb += c;
            } else 
                mp[c] --;
        }

        for(auto it = mp.begin(); it != mp.end(); it ++) {
            while(it->second > 0) {
                newa += it->first;
                it->second --;
            }
        }

        bool good = false;
        good |= solve(newa, newb, newa.size(), k);
        sort(newa.begin(), newa.end(), greater<char>());
        good |= solve(newa, newb, newa.size(), k);

        cout << (good ? "Yes\n" : "No\n");
    }
    
    return 0;
}