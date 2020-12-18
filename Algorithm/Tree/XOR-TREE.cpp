https://codeforces.com/problemset/gymProblem/308264/A

#include<iostream>
#include<stdint.h>
#include<vector>
#include<map>
#include<queue>
#define pb push_back 
#define int long long
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std; 


vector<int> ans;
void dfs(int s, vector<int> g[], vector<int> &v, int level, int in[], int sc[], int o, int e) {
	
	v[s] = 1;
	int odd = o;
	int even = e;
	if(level%2) {
		//odd
		if(in[s]!=sc[s]) {
			
			if(odd) {
				//skip
			}
			else {
				odd = 1;
				ans.push_back(s);
			}
		}
		else {
			if(odd) {
				odd = 0;
				ans.push_back(s);
			}
			else {
				odd = 0;
				//skip
			}
		}
	}
	else {
		//even
		if(in[s]!=sc[s]) {
			if(even) {
				//skip
			}
			else {
				even = 1;
				ans.push_back(s);
			}
		}
		else {
			if(even) {
				even = 0;
				ans.push_back(s);
			}
			else {
				//skip
				even = 0;
			}
		}
	}
	for(auto x: g[s]) {
		if(!v[x]) {
			dfs(x, g, v, level+1, in, sc, odd, even);
		}
	}
}


void solve() {
	int n;
	cin>>n;

	int in[n+1];
	int sc[n+1];

	vector<int> graph[n+1];

	for(int i=1; i<n; i++) {
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	

	for(int i=1; i<=n; i++) cin>>in[i];
	for(int i=1; i<=n; i++) cin>>sc[i];

	vector<int> visited(n+1, 0), dis(n+1);

	//dfs(1, graph, visited, 1, in, sc, dis);

	dfs(1, graph, visited, 0, in, sc, 0, 0);

	cout<<ans.size()<<endl;
	for(auto x: ans) cout<<x<<endl;
	

}

int32_t main() 
{ 
	speed;
	int t = 1;
	//cin>>t;

	while(t--) {
		solve();
	}
	return 0; 
} 
