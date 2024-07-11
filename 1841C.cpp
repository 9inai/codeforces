#include <bits/stdc++.h>
#define ll long long
#define ull long long
#define pairll pair<long long, long long>
#define db double
#define MOD 1000000007
#define MAXN 1004
using namespace std;

void solve(){
    ll n, m, i, j;
    string s;
    cin >> s;
    n = s.size();
    ll lA = -1, lB = -1, lC = -1, lD = -1, lE = -1;
    ll rA = -1, rB = -1, rC = -1, rD = -1, rE = -1;
    for(i = 0; i < n; i++){
        if(s[i]=='A' && lA==-1) lA = i;
        if(s[i]=='B' && lB==-1) lB = i;
        if(s[i]=='C' && lC==-1) lC = i;
        if(s[i]=='D' && lD==-1) lD = i;
        if(s[i]=='E' && lE==-1) lE = i;
        if(s[i]=='A') rA = i;
        if(s[i]=='B') rB = i;
        if(s[i]=='C') rC = i;
        if(s[i]=='D') rD = i;
        if(s[i]=='E') rE = i;
    }
    vector<ll> positions = {lA, lB, lC, lD, lE, rA, rB, rC, rD, rE};
    ll ans = LONG_LONG_MIN;
    for(auto pos: positions){
        for(char c = 'A'; c <= 'E'; c++){
            ll cnt = 0, cntA = 0, cntB = 0, cntC = 0, cntD = 0, cntE = 0;
            for(i = n-1; i >= 0; i--){
                char v = s[i];
                if(i==pos){v = c;}
                if(v=='A'){
                    if(cntB>0 || cntC>0 || cntD>0 || cntE>0) cnt-=1;
                    else cnt+=1;
                    cntA++;
                }
                if(v=='B'){
                    if(cntC>0 || cntD>0 || cntE>0) cnt-=10;
                    else cnt+=10;
                    cntB++;
                }
                if(v=='C'){
                    if(cntD>0 || cntE>0) cnt-=100;
                    else cnt+=100;
                    cntC++;
                }
                if(v=='D'){
                    if(cntE>0) cnt-=1000;
                    else cnt+=1000;
                    cntD++;
                }
                if(v=='E'){
                    cnt+=10000;
                    cntE++;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t; cin >> t; while(t--){solve();}
    return 0;
}
