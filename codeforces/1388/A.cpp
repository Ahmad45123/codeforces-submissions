#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int nums[] = {6, 10, 14, 15};
        if(n <= 30)
            cout << "NO\n";
        else {
            bool fnd = false;
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    if(i == j) continue;
                    for(int z = 0; z < 4; z++) {
                        if(z == i || z == j) continue;
                        int rem = n-nums[i]-nums[j]-nums[z];
                        if(rem > 0 && rem != nums[i] && rem != nums[j] && rem != nums[z]) {
                            cout << "YES\n";
                            cout << nums[i] << " " << nums[j] << " " << nums[z] << " " << rem << "\n";
                            fnd = true;
                            break;
                        }
                    }
                    if(fnd)
                        break;
                }
                if(fnd)
                    break;
            }
            if(!fnd)
                cout << "NO\n";
        }
    }
    
    return 0;
}