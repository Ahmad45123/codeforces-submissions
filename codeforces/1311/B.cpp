#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> nums;
vector<int> allowed;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
bool bubbleSort()  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++)  
            if (nums[j] > nums[j+1]) {
                bool good = false;
                for(int k = 0; k < m; k++) {
                    if(allowed[k] == j+1)
                    {
                        good = true;
                        break;
                    }
                }
                if(good)
                    swap(&nums[j], &nums[j+1]);
                else
                    return false;
            }
    return true;  
}  

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        nums = vector<int>(n);
        allowed = vector<int>(m);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        for(int j = 0; j < m; j++)
            cin >> allowed[j];

        if(bubbleSort()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}