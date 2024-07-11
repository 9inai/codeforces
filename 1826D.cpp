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
    cin >> n;
    vector<ll> v(n), dp0(n), dp1(n);
    ll cnt = 0;
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    for(i = 0; i < n; i++){
        cnt = max(cnt-1, v[i]);
        dp0[i] = cnt;
    }
    cnt = 0;
    for(i = 1; i < n; i++){
        cnt = max(cnt-1, dp0[i-1]-1+v[i]);
        dp1[i] = cnt;
    }
    ll ans = -1000;
    cnt = 0;
    for(i = 2; i < n; i++){
        cnt = max(cnt-1, dp1[i-1]-1+v[i]);
        ans = max(ans, cnt);
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
