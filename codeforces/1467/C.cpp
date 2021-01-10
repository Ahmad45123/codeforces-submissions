#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    vector<int> arr3(n3);
    ll sum1 = 0;
    ll sum2 = 0;
    ll sum3 = 0;
    for(int &x : arr1) {
        cin >> x;
        sum1 += x;    
    }
    for(int &x : arr2) {
        cin >> x;
        sum2 += x;    
    }
    for(int &x : arr3) {
        cin >> x;
        sum3 += x;    
    }
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    sort(arr3.begin(), arr3.end());

    ll ans1 = sum1 + sum2 + sum3 - 2LL*arr1[0] - 2LL*min(arr2[0], arr3[0]);
    ll ans5 = sum1 + sum2 + sum3 - 2LL*arr2[0] - 2LL*min(arr1[0], arr3[0]);
    ll ans6 = sum1 + sum2 + sum3 - 2LL*arr3[0] - 2LL*min(arr2[0], arr1[0]);
    ll ans2 = -sum1 + sum2 + sum3;
    ll ans3 = sum1 - sum2 + sum3;
    ll ans4 = sum1 + sum2 - sum3;

    cout << max({ans1, ans2, ans3, ans4, ans5, ans6}) << "\n";
    
    return 0;
}