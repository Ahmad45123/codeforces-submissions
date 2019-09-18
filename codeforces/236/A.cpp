#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string in; cin >> in;
    bool arr[10000];
    int num = 0;

    for(int i = 0; i < in.length(); i++) {
        if(arr[(int)in[i]] == false) {
            arr[(int)in[i]] = true;
            num ++;
        }
    }
    
    if(num % 2 == 0) {
        cout << "CHAT WITH HER!\n";
    } else {
        cout << "IGNORE HIM!\n";
    }

    return 0;
}