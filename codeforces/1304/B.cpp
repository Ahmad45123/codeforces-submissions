#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    bool processed[101];
    memset(processed, false, sizeof processed);
    vector<string> strs(n);
    for(int i = 0; i < n; i++) {
      cin >> strs[i];
    }

    vector<string> left, right;

    for(int i = 0; i < n; i++) {
      if(processed[i])
        continue;

      bool found = false;
      string reversed = strs[i];
      reverse(reversed.begin(), reversed.end());
      for(int j = i+1; j < n; j++) {
        if(reversed == strs[j]) {
          left.push_back(strs[i]);
          right.push_back(strs[j]);
          
          found = true;
          processed[j] = true;
          break;
        }
      }

      //If ALREADY palindrome, we can keep it.
      /*if(!found && strs[i].length() % 2 == 0) {
        string l = strs[i].substr(0, (strs[i].length() / 2));
        string r = strs[i].substr((strs[i].length() / 2), strs[i].length() / 2);
        cout << "Left is: " + l << "| right is " << r << "\n";
        if(l == r)
        {
          left.push_back(l);
          right.push_back(r);
        }
      }*/
    }

    int longestPalind = 0;
    int longestId = -1;
    for(int i = 0; i < n; i++) {
      string rev = strs[i];
      reverse(rev.begin(), rev.end());
      if(rev == strs[i] && rev.length() > longestPalind)
      {
        /*if(left.size() > 0 && left[left.size()-1][left[left.size()-1].length()-1] != strs[i][0])
          continue;
        if(right.size() > 0 && right[right.size()-1][0] != strs[i][strs[i].length()-1])
          continue;*/
        longestPalind = rev.length();
        longestId = i;
      }
    }

    string ans = "";
    for(int i = 0; i < left.size(); i++) {
      ans += left[i];
    }
    if(longestId != -1)
      ans += strs[longestId];
    for(int i = right.size()-1; i >= 0; i--) {
      ans += right[i];
    }

    cout << ans.length() << "\n";
    cout << ans << "\n";

    return 0;
}