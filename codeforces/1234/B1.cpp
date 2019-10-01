#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k; cin >> n >> k;
    vector<int> convos(n);
    for(int i = 0; i < n; i++)
        cin >> convos[i];

    vector<int> phone;
    map<int, bool> visible;
    for(int i = 0; i < n; i++) {
        int cur = convos[i];
        if(!visible[cur]) {
            phone.insert(phone.begin(), cur);
            visible[cur] = true;
            if(phone.size() > k) {
                int tobeRemoved = phone[phone.size()-1];
                phone.pop_back();
                visible[tobeRemoved] = false;
            }
        }
    }

    cout << phone.size() << "\n";
    for(int i = 0; i < phone.size(); i++) {
        cout << phone[i] << " ";
    }
    cout << "\n";

    return 0;
}