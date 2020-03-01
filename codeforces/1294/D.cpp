#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int q, x;
	cin >> q >> x;
	vector<int> mods(x);
	int cur = 0;
	for(int i = 0; i < q; i++) {
        int v; cin >> v;
        mods[v%x] ++;
        for(int j = cur; j <= q; j++) {
            if(mods[j%x] <= j / x) {
                cout << j << "\n";
                cur = j;
                break;
            }
        }
    }
	
	return 0;
}