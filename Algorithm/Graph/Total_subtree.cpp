//Example

//                      Input
/**
                        7
                        1 2
                        2 3
                        2 4
                        3 7
                        4 5
                        4 6
          
          
                       Output
          
          
 SubtreeArray -->      7 6 2 3 1 1 1
**/




#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

vector<vector<int>> g(100001);
vector<int> vis(100001);
vector<int> ss(100001);

int dfs(int s) {
    vis[s] = 1;
    int ch = 1;
    for(auto x: g[s]) {
        if(!vis[x]) ch += dfs(x); 
    }

    return ss[s] = ch;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    g.clear();
    for(int i=0; i<=n; i++) vis[i] = 0;



    for(int i=1; i<n; i++) {
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for(int i=1; i<=n; i++) cout<<ss[i]<<" ";

    cout<<endl;


    return 0;

}
