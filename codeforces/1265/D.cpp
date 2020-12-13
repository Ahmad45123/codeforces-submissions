#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool trySolve(int a, int b, int c, int d, string &ans) {
    int cnts[] = {a, b, c, d};
    while(true) {
        int lst = ans[ans.size()-1]-'0';
        if(lst-1 >= 0 && cnts[lst-1] > 0) {
            ans += (lst-1)+'0';
            cnts[lst-1] --;
        } else if(lst+1 <= 3 && cnts[lst+1] > 0) {
            ans += (lst+1)+'0';
            cnts[lst+1] --;
        } else {
            break;
        }
    }
    if(cnts[0] == 0 && cnts[1] == 0 && cnts[2] == 0 && cnts[3] == 0)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int a, b, c, d; cin >> a >> b >> c >> d;
    string ans = "0";
    if(a > 0 && trySolve(a-1, b, c, d, ans)) {
        cout << "YES\n";
        for(char c : ans)
            cout << c << " ";
        cout << "\n";
        return 0;
    }
    ans = "1";
    if(b > 0 && trySolve(a, b-1, c, d, ans)) {
        cout << "YES\n";
        for(char c : ans)
            cout << c << " ";
        cout << "\n";
        return 0;
    }
    ans = "2";
    if(c > 0 && trySolve(a, b, c-1, d, ans)) {
        cout << "YES\n";
        for(char c : ans)
            cout << c << " ";
        cout << "\n";
        return 0;
    }
    ans = "3";
    if(d > 0 && trySolve(a, b, c, d-1, ans)) {
        cout << "YES\n";
        for(char c : ans)
            cout << c << " ";
        cout << "\n";
        return 0;
    }

    cout << "NO\n";

    return 0;
}