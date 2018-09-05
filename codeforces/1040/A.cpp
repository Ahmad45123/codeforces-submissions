#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b; cin >> n >> a >> b;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int total = 0;
    int i = 0;
    int j = n-1;
    while(i <= j) {
        if((arr[i] == 2 && arr[j] == 0) || (arr[j] == 2 && arr[i] == 0)) {
            total += a;
        }
        else if((arr[i] == 2 && arr[j] == 1) || (arr[j] == 2 && arr[i] == 1)) {
            total += b;
        }
        else if(arr[i] == 2 && arr[j] == 2) {
            if(i == j)
                total += min(a, b);
            else
                total += min(a*2, b*2);
        }
        else if(arr[i] != arr[j]) {
            cout << -1 << '\n';
            return 0;
        }

        i++;
        j--;
    }
    
    cout << total << '\n';

    return 0;
}