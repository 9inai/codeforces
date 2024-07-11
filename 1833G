#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define db double
#define pairll pair<long long, long long>
using namespace std;

vector<vector<pairll>> v;
vector<ll> ans, vis;

ll dfs(ll p){
    //cout << "dfs " << p << endl;
    vis[p] = 1;
    ll power = 1;
    for(ll i = 0; i < v[p].size(); i++){
        if(!vis[v[p][i].first]){
            ll d = dfs(v[p][i].first);
            if(d==-1)return -1;
            if(d==3){
                ans.push_back(v[p][i].second);
            }
            else power+=d;
        }
    }
    if(power>3)return -1;
    return power;
}

void solve(){
    ll n, i, j, p, q;
    cin >> n;
    v.assign(n, {});
    ans = {};
    vis.assign(n, 0);
    for(i = 1; i < n; i++){
        cin >> p >> q;
        p--; q--;
        v[p].push_back({q, i});
        v[q].push_back({p, i});
    }
    if(dfs(0)==3){
        //print ans
        cout << ans.size() << endl;
        for(i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << -1 << endl << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t; while(t--){solve();}
    return 0;
}
