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
    vector<ll> v(n), l(n+1), r(n+1);
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    ll cnt = 0;
    l[0] = cnt;
    for(i = 1; i < n; i++){
        if(v[i-1]<=v[i])cnt++;
        l[i] = cnt;
    }
    cnt = 0;
    r[n-1] = cnt;
    for(i = n-2; i >= 0; i--){
        if(v[i]>=v[i+1])cnt++;
        r[i] = cnt;
    }
    ll ans = min(r[0], l[n-1]+1);
    for(i = 1; i < n; i++){
        ans = min(ans, l[i-1]+r[i]+1);
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
