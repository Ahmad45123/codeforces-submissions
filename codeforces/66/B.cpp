    #include <bits/stdc++.h>

    using namespace std;
    #define mp make_pair
    typedef long long int ll;

    int main()
    {
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        int globalAns = 0;

        for(int i = 0; i < n; i++) {
            int prevB = arr[i];
            int prevA = arr[i];
            int ans = 1;
            int b = i-1, a = i+1;
            while(true) {
                if(b >= 0 && arr[b] <= prevB) {
                    ans++;
                    prevB = arr[b];
                    b--;
                }
                else {
                    b = -1; //no more
                }

                if(a < n && arr[a] <= prevA) {
                    ans++;
                    prevA = arr[a];
                    a++;
                }
                else {
                    a = n; //no more
                }

                if(b < 0 && a >= n)
                    break;
            }

            globalAns = max(globalAns, ans);
        }

        cout << globalAns;
        return 0;
    }