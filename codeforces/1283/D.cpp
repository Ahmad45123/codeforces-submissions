#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class tree {
    public:
        int pos;
        int dist;
        bool dir;
};

bool operator < (const tree& lhs, const tree& rhs)
{
    return lhs.dist < rhs.dist;
}

bool operator > (const tree& lhs, const tree& rhs)
{
    return lhs.dist > rhs.dist;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> tmpTrees(n);
    map<int, bool> hasTree;
    for(int i = 0; i < n; i++) {
        cin >> tmpTrees[i];
        hasTree[tmpTrees[i]] = true;
        
    }

    priority_queue<tree, vector<tree>, greater<vector<tree>::value_type>> trees;
    vector<int> ans;
    ll totalDist = 0;
    
    for(int i = 0; i < n; i++) {
        int x = tmpTrees[i];
        if(!hasTree[x+1]) {
            tree tmp;
            tmp.pos = x+1;
            tmp.dist = 1;
            tmp.dir = 1;
            trees.push(tmp);
        }
        if(!hasTree[x-1]) {
            tree tmp;
            tmp.pos = x-1;
            tmp.dist = 1;
            tmp.dir = 0;
            trees.push(tmp);
        }
    }
    
    for(int i = 0; i < m; i++) {
        while(hasTree[trees.top().pos])
            trees.pop();
            
        tree closest = trees.top();
        trees.pop();
        ans.push_back(closest.pos);
        hasTree[closest.pos] = true;
        totalDist += closest.dist;
        
        if(closest.dir == 1 && !hasTree[closest.pos+1]) {
            tree tmp;
            tmp.dir = 1;
            tmp.pos = closest.pos+1;
            tmp.dist = closest.dist+1;
            trees.push(tmp); 
        }
        else if(closest.dir == 0 && !hasTree[closest.pos-1]) {
            tree tmp;
            tmp.dir = 0;
            tmp.pos = closest.pos-1;
            tmp.dist = closest.dist+1;
            trees.push(tmp);
        }
    }

    cout << totalDist << "\n";
    for(vector<int>::iterator i = ans.begin(); i != ans.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";

    return 0;
}