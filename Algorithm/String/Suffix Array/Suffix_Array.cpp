#include <bits/stdc++.h>
 
#define int long long
#define endl "\n"
 
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define SQR(n)                ( n * n )
/// Math End
/// Pair Start
#define F                    first
#define S                    second
#define mp                    make_pair
/// Pair End
/// Array Start
#define SET(a)                memset( a, -1,    sizeof a )
#define CLR(a)                memset( a,  0,    sizeof a )
#define MEM(a,val)            memset( a,  val,  sizeof(a) )
/// Array End
/// Extra Start
#define pb                    push_back
#define SS                    stringstream
#define ull                   unsigned long long
#define mod                   1000000007
#define INF                   2147483647
#define SIZE                  2000001
#define _cin                  ios_base::sync_with_stdio(0);  cin.tie(0);
 
using namespace std;

void count_sort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    
        vector<int> cnt(n);

        for(auto x: c) cnt[x]++;

        vector<int> p_new(n);
        vector<int> pos(n);

        pos[0] = 0;
        for(int i=1; i<n; i++) {
            pos[i] = pos[i-1] + cnt[i-1];
        }

        for(auto x: p) {
            int i = c[x];
            p_new[pos[i]] = x;
            cout<<"i is: "<<i<<" pos[i] is : "<<pos[i]<<" = "<<x<<" ";
            pos[i]++;
        }
        cout<<endl;
        p = p_new;
}
/**

vector<int> find_lcp(string s, vector<int> &p) {    //Done using kasais Algo

    int n = p.size();
    vector<int> rank(n);
    vector<int> height(n);
    for (int i = 0; i < n; ++i)
        rank[p[i]] = i;
    height[0] = 0;
    for (int i = 0, h = 0; i < n; ++i) {
        if (rank[i] > 0) {
            int j = p[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h])
                h++;
            height[rank[i]] = h;
            if (h > 0)
                h--;
        }
    }



    return height;
}

*/
void solve() {
    string s;
    cin>>s;

    s+= '$';
    
    int n = s.size();

    vector<int> c(n),p(n);

    {
        vector<pair<char, int>> a(n);
    
        for(int i=0; i<s.size(); i++) {
            a[i] = {s[i], i};
        }

        sort(a.begin(), a.end());

        for(int i=0; i<n; i++) p[i] = a[i].S;
    
        c[p[0]] = 0;

        for(int i=1; i<n; i++) {
            if(a[i].F == a[i-1].F) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
    }

    int k = 0;

    while((1<<k) < n) {
        
        for(int i=0; i<n; i++) {
            p[i] = (p[i] - (1<<k) + n) % n;
        }

        count_sort(p, c);

        vector<int> c_new(n);
        c_new[p[0]] = 0;

        for(int i=1; i<n; i++) {
            pair<int, int> curr = {c[p[i]], c[(p[i] + (1<<k))%n]};
            pair<int, int> prev = {c[p[i-1]], c[((p[i-1] + (1<<k))%n)]};
            if(curr == prev) c_new[p[i]] = c_new[p[i-1]];
            else c_new[p[i]] = c_new[p[i-1]] + 1;
        }
        c = c_new;
        k++;
    }

    //this is the suffix array which contains sorted array of substrings of the string

    for(auto x: p) {
        cout<<x<<" "<<s.substr(x, n-x)<<endl;
    }
    cout<<endl;
    
    
}
int32_t main() {
    _cin
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
    return 0;
}
