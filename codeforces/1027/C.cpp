#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

   long long t;cin>>t;
  // pair<string,int>l[100009];

   long long a,b;
  //  ios_base::sync_with_stdio(false);


while(t--){
   long long  n;cin>>n;
      vector<long long >arr;
      map<int, bool> passed;
        for(int i = 0; i < n; i++) {
            long long  temp; cin >> temp;
            if(passed[temp]) {
                arr.push_back(temp);
                passed[temp] = false;
                continue;
            }
            passed[temp] = true;
        }
        sort(arr.begin(),arr.end());
      double  lol=999999;
 for(int i = 1; i < arr.size(); i++) {
          double  rr=(arr[i]*1.0f/arr[i-1]);
           if(rr<lol){lol=rr;
           a=arr[i],b=arr[i-1];
           }

        }

cout<<a<<" "<<a<<" "<<b<<" "<<b<<'\n';

}


}