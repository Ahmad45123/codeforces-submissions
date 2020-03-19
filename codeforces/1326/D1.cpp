#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

bool isPalind(string s, int i , int j) {
    while(j >= i) {
        if(s[i] != s[j])
            return false;
        i ++;
        j --;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        int ai = 0, aj = n-1;
        string left = "", right = "";
        while(aj > ai) {
            if(s[ai] == s[aj]) {
                left += s[ai];
                right = s[aj] + right;
                ai ++;
                aj --;
            } else break;
        }
        
        int i = ai, j = aj;
        string ansa = "";
        while(j >= i) {
            if(s[i] == s[j]) {
                if(isPalind(s, i, j))
                {
                    string tmp = s.substr(i, j-i+1);
                    if(tmp.size() > ansa.size())
                        ansa = tmp;
                }
            }
            j--;
        }

        i = ai, j = aj;
        string ansb = "";
        while(j >= i) {
            if(s[i] == s[j]) {
                if(isPalind(s, i, j))
                {
                    string tmp = s.substr(i, j-i+1);
                    if(tmp.size() > ansb.size())
                        ansb = tmp;
                }
            }
            i++;
        }

        if(ansa.size() > ansb.size())
            cout << left+ansa+right << "\n";
        else
            cout << left+ansb+right << "\n";
    }
    
    return 0;
}