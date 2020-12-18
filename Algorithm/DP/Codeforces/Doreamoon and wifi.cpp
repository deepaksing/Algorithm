//question :  --> https://codeforces.com/problemset/problem/476/B

#include<iostream>
#include<stdint.h>
#include<vector>
#include<iomanip>
#include<map>
#include<queue>
#define pb push_back 
#define int long long
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;

double tc=0, pc=0;



int dest = 0;
 
void rec(int i, string s, int pos) {
    if(i == s.length()) {
        tc++;
        if(pos == dest) pc++;
        return;
    }
    if(s[i] == '+') rec(i+1, s, pos+1);
    else if(s[i] == '-') rec(i+1, s, pos-1);
    else {
        s[i] = '+';
        rec(i, s, pos);
        s[i] = '-';
        rec(i, s, pos);
    }
}

int32_t main() {
	
	string s;
	cin>>s;
	
	string t;
	cin>>t;
	
    
    int ans[s.length()];
    for(int i=0; i<s.length(); i++) {
        //cout<<s[i]<<endl;
        if(s[i] == '+') dest++;
        else dest--;
        ans[i] = dest;
    }
    rec(0, t, 0);
    cout<<fixed;
    cout<<setprecision(9);
    cout<<pc/tc<<endl;
    return 0;
}
