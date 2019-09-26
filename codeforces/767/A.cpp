#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    int cur = n;
    priority_queue<int> nums;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        nums.push(k);
        while(nums.size() != 0 && nums.top() == cur) {
            cout << cur << " ";
            nums.pop();
            cur --;
        }
        cout << "\n";
    }
    
    return 0;
}