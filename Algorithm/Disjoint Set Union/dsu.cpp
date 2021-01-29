//https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
#include<bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

vector<int> Rank;
vector<int> parent;
int findParent(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
   return x;
}

void UNION(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(Rank[a] < Rank[b]){
        parent[a]=b;
    }else if(Rank[a] > Rank[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
        Rank[b]++;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
cin.tie(0);
    int n, q;
    cin>>n>>q;

    Rank.resize(n+1);
    parent.resize(n+1);
    
    for(int i=0; i<=n; i++) {
        Rank[i] = 0;
        parent[i] = i;
    }

    for(int i = 0; i<q; i++) {
        string s;
        int a, b;

        cin>>s>>a>>b;

        if(s == "union") UNION(a, b);
        else {
            a = findParent(a);
            b = findParent(b);

            if(a == b) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }


    return 0;

}