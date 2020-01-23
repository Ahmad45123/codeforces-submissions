#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char, int> digits;
void getSum() {
    int ans = 0;
    map<char, int> tmp;
    for(char c = '1'; c <= '9'; c++) {
        ans += digits[c]*(c-'0');
    }
    string sum = to_string(ans);
    for(int i = 0; i < sum.length(); i++) 
        tmp[sum[i]] ++;
    digits = tmp;
}

int getLength() {
    int tmp = 0;
    for(char c = '0'; c <= '9'; c++)
        tmp += digits[c];
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++)
        digits[s[i]] ++;

    int ans = 0;
    while (getLength() > 1)
    {
        getSum();
        ans ++;
    }
    
    cout << ans << "\n";

    return 0;
}