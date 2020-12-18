//ques --> https://codeforces.com/problemset/problem/1420/C1

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

void solve() {
	int n, q;
	cin>>n>>q;

	int a[n];

	for(int i=0; i<n; i++) cin>>a[i];

	vector<int> ans;

	int diff[n];
	int curr = 0;
	diff[0] = 0;

	for(int i=1; i<n; i++) {
		diff[i] = a[i-1] - a[i];
	}

	if(diff[1] > 0) {
		ans.push_back(a[0]);
		curr = 1;
	}
	else curr = 0;

	for(int i=1; i<n; i++) {
		if(curr == 1) {
			if(diff[i] > 0) continue;
			else {
				ans.push_back(a[i-1]);
				curr = 0;
			}
		}
		else {
			if(diff[i]<0) continue;
			else {
				ans.push_back(a[i-1]);
				curr = 1;
			}

		}
	}

	if(curr == 0 && diff[n-1]<0) ans.pb(a[n-1]);

	int fa = 0;
	int len = 1;
	for(auto x: ans) {
		if(len%2) fa += x;
		else fa += x*(-1);
		len++;
	}
	cout<<fa<<endl;

	
}

int32_t main() 
{ 
	speed;
	int t;
	cin>>t;

	while(t--) {
		solve();
	}
	return 0; 
} 
