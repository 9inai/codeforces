#include <bits/stdc++.h>
#define ll long long
#define ull long long
#define pairll pair<long long, long long>
#define db double
#define MOD 1000000007
#define MAXN 1004
using namespace std;

void solve(){
    ll n, m, i, j, k, p, q;
    string s;
    cin >> n >> s;
    s+=string(n, '0');
    string ans(n, '0');
    for(k = 0; k < min(n, 25LL); k++){
        string z = s.substr(0, n);
        for(j = k; j < n; j++){
            if(s[j]=='1' or s[j-k]=='1'){
                z[j] = '1';
            }
        }
        ans = max(ans, z);
    }
    for(i = 0; i < n; i++){
        if(ans[i]=='1' or n==i+1)break;
    }
    for(; i< n; i++){
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();//ll t; cin >> t; while(t--){solve();}
    return 0;
}
