#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr;
        map<int, bool> passed;
        for(int i = 0; i < n; i++) {
            int temp; cin >> temp;
            if(passed[temp]) {
                arr.push_back(temp);
                passed[temp] = false;
                continue;
            }
            passed[temp] = true;
        }
        n = arr.size();

        sort(arr.begin(), arr.end());

        double diff = DBL_MAX;
        int x, y;
        for(int i = 1; i < n; i++) {
            double tmp = arr[i]*1.0f / arr[i-1];
            if(tmp < diff) {
                diff = tmp;
                x = arr[i];
                y = arr[i-1];
            }
        }

        cout << x << " " << x << " " << y << " " << y << endl;
    }
    return 0;
}
