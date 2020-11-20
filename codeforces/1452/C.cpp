#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// function to check if brackets are balanced 
int countOne(string expr) 
{   
    stack<char> s; 
    char x; 

    int ans = 0;
  
    for (int i = 0; i < expr.length(); i++)  
    { 
        if (expr[i] == '(')  
        { 
            s.push(expr[i]); 
            continue; 
        } 
  
        if (s.empty()) 
            continue;
  
        switch (expr[i]) { 
            case ')': 
                if (s.top() == '(') {
                    s.pop();
                    ans ++; 
                }
                break; 
        }
    } 

    return ans;
}

int countTwo(string expr) 
{   
    stack<char> s; 
    char x; 

    int ans = 0;
  
    for (int i = 0; i < expr.length(); i++)  
    { 
        if (expr[i] == '[')  
        { 
            s.push(expr[i]); 
            continue; 
        } 
  
        if (s.empty()) 
            continue;
  
        switch (expr[i]) { 
            case ']': 
                if (s.top() == '[') {
                    s.pop();
                    ans ++; 
                }
                break; 
        }
    } 

    return ans;
} 

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << countOne(s)+countTwo(s) << "\n";
    }
    
    return 0;
}