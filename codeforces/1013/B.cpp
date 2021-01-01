#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    
    sort(arr.begin(), arr.end());
    for(int i = 1; i < n; i++)
        if(arr[i] == arr[i-1]) {
            cout << "0\n";
            return 0;
        }

    set<int> nonConverted;
    for(int x : arr)
        nonConverted.insert(x);
    
    for(int i = 0; i < n; i++) {
        nonConverted.erase(arr[i]);
        if(nonConverted.find(arr[i] & x) != nonConverted.end()) {
            cout << "1\n";
            return 0;
        }
        nonConverted.insert(arr[i]);
        arr[i] = arr[i] & x;
    }

    sort(arr.begin(), arr.end());
    for(int i = 1; i < n; i++)
        if(arr[i] == arr[i-1]) {
            cout << "2\n";
            return 0;
        }

    cout << "-1\n";
    return 0;
}