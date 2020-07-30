#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    
    vector<int> bits(21);

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 20; j++) {
            if (arr[i] & (1 << (j - 1))) {
                bits[j] ++;
            }
        }
    }

    vector<int> nums;

    for(int i = n; i >= 1; i--) {
        int num = 0;
        for(int j = 1; j <= 20; j ++) {
            if(bits[j] == i) {
                num = ((1 << (j-1)) | num);
                bits[j] --;
            }
        }
        nums.push_back(num);
    }

    ll ans = 0;
    for(int i = 0; i < nums.size(); i++) {
        ans += powl(nums[i], 2);
    }

    cout << ans << "\n";
    
    return 0;
}