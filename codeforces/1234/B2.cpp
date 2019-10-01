#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k; cin >> n >> k;
    list<int> phone;
    vector<bool> visible(1000000000, false);
    
    for(int i = 0; i < n; i++) {
        int cur;
        cin >> cur;

        if(!visible[cur]) {
            phone.push_front(cur);
            visible[cur] = true;
            if(phone.size() > k) {
                int tobeRemoved = phone.back();
                visible[tobeRemoved] = false;
                phone.pop_back();
            }
        }
    }

    list<int>::iterator it;
    cout << phone.size() << "\n";
    for(it = phone.begin(); it != phone.end(); ++it){
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}