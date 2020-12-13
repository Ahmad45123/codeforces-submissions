#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a > b || d > c) {
        int cntZeros = 0;
        if(a == 0) cntZeros ++;
        if(b == 0) cntZeros ++;
        if(c == 0) cntZeros ++;
        if(d == 0) cntZeros ++;
        if(cntZeros == 0 || cntZeros == 1)
            cout << "NO\n";
        else if(cntZeros == 3) {
            if(a == 1)
                cout << "YES\n0\n";
            else if(b == 1)
                cout << "YES\n1\n";
            else if(c == 1)
                cout << "YES\n2\n";
            else if(d == 1)
                cout << "YES\n3\n";
            else {
                cout << "NO\n";
            }
        }
        else if(cntZeros == 4) //CANT HAPPEN THO
            cout << "YES\n";
        else {
            if(a != 0 && b != 0) {
                string ans = "";
                while(a > 0 && b > 0) {
                    ans += "0 1 ";
                    a --;
                    b --;
                }
                if(a == 1)
                    ans += "0", a --;
                else if(b == 1)
                    ans = "1 " + ans, b --;
                if(a == 0 && b == 0)
                    cout << "YES\n" << ans << "\n";
                else
                    cout << "NO\n";
            } else if(b != 0 && c != 0) {
                string ans = "";
                while(b > 0 && c > 0) {
                    ans += "0 1 ";
                    c --;
                    b --;
                }
                if(b == 1)
                    ans += "1", b--;
                else if(c == 1)
                    ans = "2 " + ans, c--;
                if(c == 0 && b == 0)
                    cout << "YES\n" << ans << "\n";
                else
                    cout << "NO\n";
            } else if(c != 0 && d != 0) {
                string ans = "";
                while(c > 0 && d > 0) {
                    ans += "2 3 ";
                    c --;
                    d --;
                }
                if(c == 1)
                    ans += "2", c--;
                else if(d == 1)
                    ans = "3 " + ans, d--;
                if(c == 0 && d == 0)
                    cout << "YES\n" << ans << "\n";
                else
                    cout << "NO\n";
            } else {
                cout << "NO\n";
            }
        }
        return 0;
    }

    string left = "";
    string mid = "";
    string right = "";
    while(a > 0) {
        left += "0 1 ";
        b --;
        a --;
    }

    while(d > 0) {
        right += "2 3 ";
        c --;
        d --;
    }

    while(b > 0 && c > 0) {
        mid += "2 1 ";
        b --;
        c --;
    }

    if(b == 1)
        left = "1 " + left, b--;
    if(c == 1)
        right += "2", c--;
    
    if(a == 0 && b == 0 && c == 0 && d == 0)
        cout << "YES\n" << left << mid << right << "\n";
    else
        cout << "NO\n";

    return 0;
}