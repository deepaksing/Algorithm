//codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

const int N = 1e5;

int seg_tree[4*N];
int arr[N];

void build_seg(int curr, int low, int high) {
    if(low > high) return;
    if(low == high) {
        seg_tree[curr] = arr[low];
        return;
    }

    int mid = (low + high)/2;
    build_seg(2*curr+1, low, mid);
    build_seg(2*curr+2, mid+1, high);

    seg_tree[curr] = seg_tree[2*curr+1] + seg_tree[2*curr+2];
}


int sum(int curr, int low, int high, int l, int r) {

    if(l<=low && r>=high) return seg_tree[curr];
    if(high<l || low > r) return 0;

    int mid = (low + high)/2;

    int left = sum(2*curr + 1, low, mid, l, r);
    int right = sum(2*curr + 2, mid+1, high, l, r);

    return (left + right);
}

void update(int curr, int low, int high, int pos, int val) {
    
    if(low == high) seg_tree[curr] = val;

    else {
        int mid = (low + high)/2;
        if(pos <= mid) update(2*curr + 1, low, mid, pos, val);
        else update(2*curr + 2, mid+1, high, pos, val);
        seg_tree[curr] = seg_tree[2*curr + 1] + seg_tree[2*curr + 2];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++) cin>>arr[i];

    build_seg(0, 0, n);

    for(int i=0; i<m; i++) {
        int x, y, z;
        cin>>x>>y>>z;
        if(x == 1) update(0, 0, n, y, z);
        else cout<<sum(0, 0, n, y, z-1)<<endl;
    }
 
    return 0;
}
