#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int subArraySum(vector<int> arr, int sum) 
{ 
    int n = arr.size();
    int curr_sum = arr[0], start = 0, i; 
    int numbers = 1;

    for (i = 1; i <= n; i++) 
    { 
        while (curr_sum > sum && start < i - 1) 
        { 
            curr_sum = curr_sum - arr[start];
            numbers -- ;
            start++; 
        } 

        if (curr_sum == sum && numbers > 1) 
        {  
            return 1; 
        } 
  
        if (i < n) {
            curr_sum = curr_sum + arr[i];
            numbers ++;
        } 
    } 
    return 0; 
} 

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(auto &x : arr) {
            cin >> x;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(subArraySum(arr, arr[i]))
                ans ++;
        }

        cout << ans << "\n";
    }
    
    return 0;
}