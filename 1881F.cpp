#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define db double
#define pairll pair<long long, long long>
using namespace std;

vector<vector<ll>> v;
vector<ll> vis, dp, mark;
ll ans = 0;

ll dfs(ll p, ll best){
    //cout << "dfs " << p << endl;
    ll deepest = INT_MIN;
    vis[p] = 1;
    if(mark[p]==1){
        deepest = 0;
        best = max(0LL, best);
    }
    dp[p] = best;
    for(ll i = 0; i < v[p].size(); i++){
        if(!vis[v[p][i]]){
            ll d = dfs(v[p][i], dp[p]+1);
            deepest = max(deepest, d);
            dp[p] = max(dp[p], d);
        }
    }
    if(mark[p])ans = max(ans, dp[p]);
    return deepest+1;
}

void solve(){
    ll n, i, j, p, q, k;
    cin >> n >> k;
    ans = 0;
    v.assign(n, {});
    vis.assign(n, 0);
    mark.assign(n, 0);
    dp.assign(n, INT_MIN);
    for(i = 0; i < k; i++){
        cin >> p;
        mark[p-1] = 1;
    }
    for(i = 1; i < n; i++){
        cin >> p >> q;
        p--; q--;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    if(k==1){cout << 0 << endl; return;}
    ll i_dont_care = dfs(0, INT_MIN);
    cout << (ll)ceil(ans/2.0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t; while(t--){solve();}
    return 0;
}
