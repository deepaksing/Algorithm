#include <bits/stdc++.h>
#define int long long
#define endl "\n" 

using namespace std;

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

/////////////////////////////////////////////////////////

vector<int> o,ni,w;

int dp[22][80][1001];
 
int knapsack(int oc, int nc, int n) {
    if(oc<=0 && nc<=0) return dp[oc][nc][n] = 0;
    if(dp[oc][nc][n] != -1) return dp[oc][nc][n];
    else if(n<=0) dp[oc][nc][n] = INT_MAX;
    else 
    dp[oc][nc][n] =  min(knapsack(oc, nc, n-1), w[n-1] + knapsack(((oc-o[n-1] < 0)?0:oc-o[n-1]), ((nc-ni[n-1] < 0)?0:nc-ni[n-1]), n-1));
    return dp[oc][nc][n];
}

void solve() {
  int oc, nc;
  cin>>oc>>nc;
  int n;
  cin>>n;
  memset(dp, -1, sizeof(dp));
  o.resize(n);
  ni.resize(n);
  w.resize(n);

  for(int i=0; i<n; i++) cin>>o[i]>>ni[i]>>w[i];

  cout<<knapsack(oc, nc, n)<<endl;
}
 
int32_t main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
	return 0;
}