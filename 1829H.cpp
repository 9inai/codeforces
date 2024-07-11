#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define db double
#define pairll pair<long long, long long>
using namespace std;

void solve(){
    ll n, i, j, x, k;
    cin >> n >> k;
    vector<ll> v(n), dp0(64, 0), dp1(64);
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    dp0[63] = 1;
    for(i = 0; i < n; i++){
        dp1 = dp0;
        for(j = 0; j < 64; j++){
            dp1[j & v[i]] += dp0[j];
            dp1[j&v[i]]%=MOD;
        }
        dp0 = dp1;
    }
    ll ans = 0;
    for(j = 0; j < 64; j++){
        if(__builtin_popcount(j)==k){
            ans = (ans + dp0[j])%MOD;
        }
    }
    cout << ans-(k==__builtin_popcount(63)) << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t; while(t--){solve();}
    return 0;
}
