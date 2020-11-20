//https://www.spoj.com/problems/DQUERY/


#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

int q[200001];
int a[30001], ans[200001];
int freq[1000001];
int cnt = 0;

struct query {
	int l,r,index;
};

const int block_size = 555;

bool compare(query x, query y) {
	if(x.l/block_size != y.l/block_size) return x.l/block_size < y.l/block_size;
	return x.r<y.r;
	
}


void add(int index) {
	freq[a[index-1]]++;
	if(freq[a[index-1]] == 1)cnt++;
}

void remove(int index) {
	freq[a[index-1]]--;
	if(freq[a[index-1]] == 0) cnt--;
}

void solve() {
	int n;
	cin>>n;

	for(int i=0; i<n; i++) cin>>a[i];

	int m;
	cin>>m;

	query q[m];
	for(int i=0; i<m; i++) {
		int u,v;
		cin>>u>>v;
		q[i].l = u;
		q[i].r = v;
		q[i].index = i;
	}

	sort(q, q+m, compare);
	int mr = 0, ml = 1;
	for(int i=0; i<m; i++) {
		int l = q[i].l;
		int r = q[i].r;
		int pos = q[i].index;

		//1 2 1 1 3

		while(mr < r) {
			mr++;
			add(mr);
		}

		while(ml < l) {
			remove(ml);
			ml++;
		}

		while(mr > r) {
			remove(mr);
			mr--;
		}

		while(ml > l) {
			ml--;
			add(ml);
		}



		ans[pos] = cnt;

	}

	for(int i=0; i<m; i++) cout<<ans[i]<<endl;
	
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	//cin>>t;

	while(t--) {
		solve();
	}
	return 0;
}