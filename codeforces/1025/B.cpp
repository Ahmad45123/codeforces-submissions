    #include <bits/stdc++.h>

    using namespace std;
    #define mp make_pair
    typedef long long int ll;

    ll n;
    vector<pair<ll, ll>> arr;

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        cin >> n;
        arr = vector<pair<ll, ll>>(n);
        for(ll i = 0; i < n; i++)
        {
            ll a, b; cin >> a >> b;
            arr[i] = {a,b};
        }
        
        vector<ll> divs;
        for(ll i = 2; i*i <= arr[0].first; i++) {
            if(arr[0].first % i == 0) {
                divs.push_back(i);
                while(arr[0].first % i == 0)
                    arr[0].first /= i;
            }
        }
        if(arr[0].first > 1) divs.push_back(arr[0].first);

        for(ll i = 2; i*i <= arr[0].second; i++) {
            if(arr[0].second % i == 0) {
                divs.push_back(i);
                while(arr[0].second % i == 0)
                    arr[0].second /= i;  
            }
        }
        if(arr[0].second > 1) divs.push_back(arr[0].second);

        for(ll j = 0; j < divs.size(); j++) {
            ll good = true;
            for(ll i = 1; i < n; i++) {
                if(arr[i].first % divs[j] != 0 && arr[i].second % divs[j] != 0)
                {
                    good = false;
                    break;
                }
            }
            if(good) {
                cout << divs[j];
                return 0;
            }
        }

        cout << -1;
        return 0;
    }