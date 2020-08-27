#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

void dfs(int i, vector<int> &v, vector<int> g[]) {
    v[i] = 1;
    for(auto x: g[i]) {
        if(v[x] == 0) {
            dfs(x, v, g);
        }
    }
}

int32_t main() {
    
    int n,e;
    cin>>n>>e;

    vector<int> g[n+1];

    for(int i=1; i<=e; i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }     

    vector<int> v1(n+1);
    for(int i=1; i<=n; i++) {
        v1[i] = 0;
    }

    int count = 0;

    for(int i=1; i<=n; i++) {
        if(v1[i] == 0) {
            dfs(i,v1,g);
            count++;
        }
    }

    cout<<count<<endl;
    return 0;
}