        1
      2   3
    4  5   6
   7      8 




////                         OUTPUT:
    
    
    //               starts from 7 ---> 8  and distance: 7
    
    ///--------------------------------------------------------------------------------------------
    
    #include<bits/stdc++.h>
    #define int long long
    #define endl "\n"

    using namespace std;

    vector<vector<int>> g(100001);
    vector<int> vis(100001);
    vector<int> height(100001);

    int mh = INT_MIN;

    void dfs(int s, int h) {
        vis[s] = 1;
        height[s] = h;
        mh = max(mh, h);
        
        for(auto x: g[s]) {
            if(!vis[x]) dfs(x, h+1);
        }
    }

    int32_t main() {

        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n,m;
        cin>>n>>m;

        for(int i=0; i<=n; i++) vis[i] = 0;
        g.clear();
        height.clear();

        for(int i=0; i<m; i++) {
            int u,v;
            cin>>u>>v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, 1);
        int farthest;

        for(int i=0; i<=n; i++) {
            if(height[i] == mh) farthest = i;
        }
        
        height.clear();
        mh = INT_MIN;
        for(int i=0; i<=n; i++) vis[i] = 0;

        dfs(farthest, 1);
        int nf;
        for(int i=0; i<=n; i++) {
            if(height[i] == mh) nf = i;
        }

        cout<<"starts from "<<nf<<" ---> "<<farthest<<"  and distance: "<<mh<<endl;

        return 0;

    }
