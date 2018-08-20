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
        map<int, int> passed;
        for(int i = 0; i < n; i++) {
            int temp; cin >> temp;
            passed[temp] ++;
        }

        vector<int> arr;
        for(auto it = passed.begin(); it != passed.end(); it++) {
            if((*it).second >= 2)
                arr.push_back((*it).first);
        }
        n = arr.size();

        double diff = DBL_MAX;
        int x, y;
        for(int i = 0; i < n; i++) {
            if(passed[arr[i]] >= 4) {
                x = y = arr[i];
                break;
            }

            if(i == 0) continue;

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