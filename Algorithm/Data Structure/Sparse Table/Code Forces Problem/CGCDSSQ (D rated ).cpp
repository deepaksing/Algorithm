#include<iostream>
#include<stdint.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cmath>
#include<stack>

#define int long long
#define   endl    '\n'
#define   input(n)     scanf("%lld",&n)
#define   mp      make_pair
#define   pb      push_back
#define   ppb     pop_back
#define   fi      first
#define   se      second
#define   ld      long double
#define   pii     pair<int, int>
#define   f(i,a,b)  for(ll i = (ll)(a); i < (ll)(b); i++)
#define   rf(i,a,b)   for(ll i = (ll)(a); i > (ll)(b); i--)
#define   memset(a,b)   memset((a),(b),sizeof(a))
#define   abs(x)    ((x<0)?(-(x)):(x))
#define   MAX     200005
#define   inf     LLONG_MAX
#define   ninf    LLONG_MIN
#define   MIN     INT_MIN


using namespace std;

#define tihs if(fopen("input.txt","r"))freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

inline int  MAX2(int  a, int  b){return (a)>(b)?(a):(b);}
inline int  MAX3(int  a, int  b,int  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline int  MIN2(int  a, int  b){return (a)<(b)?(a):(b);}
inline int  MIN3(int  a, int b,int c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}


int mod = 1e9 +7 ;
int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {if (!a) {x = 0;y = 1;return b;}int64_t x1, y1;int64_t d = extGcd(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
inline int addmod(int a,int b){a=a%mod+b%mod;if(a>mod)a%=mod;return a;}
inline int submod(int a,int b){a=a%mod-b%mod;if(a<0)a+=mod;return a;}
inline int mulmod(int a,int b){return (a%mod * b%mod)%mod;}

int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};
inline int exp(int a,int b){if(a==0)return 0ll;int r=1LL;while(b>0){if(b&1){r=r*(a%mod);r=(r+mod)%mod;}b/=2;a=(a%mod)*(a%mod);a=(a+mod)%mod;}return (r+mod)%mod;}
int gcd(int a,int b){if(b==0)return a;if(a==0)return b;return gcd(b,a%b);}
//uint32 setbits(ll n){uint32 count=0;while (n){n&=(n-1);count++;}return count; }
using namespace std; 
/****************************************************************************************/


int gccd(int a, int b) {
    if(b == 0) return a;
    else return gccd(b, a%b);
}


void solve() {
    int n;
    cin>>n;
    
    int k = log(n)+2;
    vector<vector<int>> st(n, vector<int>(20));
    int a[n+3];

    for(int i=0; i<n; i++) cin>>a[i]; //input array

    int q; //queries
    cin>>q;

    int logg[n+3];
    logg[1] = 0;
    for (int i = 2; i <= n; i++)
        logg[i] = logg[i/2] + 1;

    for(int i=0; i<n; i++) st[i][0] = a[i];

    for(int j = 1; (1<<j)<=n; j++) {
        for(int i = 0; (i + (1<<j))<=n; i++) {
            st[i][j] = gccd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    auto get =
    [&](int x, int y) {
      int k = logg[y - x + 1];
      return gcd(st[x][k], st[y - (1 << k) + 1][k]);
    };

    map<int, int> count;

    for(int l = 0; l<n; l++) {
            for(int r = l; r<n;) {
                            
                int target = get(l, r);
                int low = r, high = n - 1;
                while (low != high) {
                    int mid = (low + high + 1) / 2;
                    if (get(l, mid) != target) {
                    high = mid - 1;
                    } else {
                    low = mid;
                    }
                }
                count[target] += high - r + 1;
                r = high + 1;
            }
        }


// cout<<endl;
    for(int i=0; i<q; i++) {
        int x;
        cin>>x;
        cout<<count[x]<<endl;
    }
}

int32_t main() {
    
    int t = 1;
    //cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}