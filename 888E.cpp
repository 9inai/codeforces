#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pairll pair<long long, long long>
#define db double
using namespace std;

void solve(){
    ll n, i, j, k, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(i = 0; i < n; i++){
        cin >> v[i];
        v[i]%=m;
    }
    sort(v.begin(), v.end());
    ll mid = n/2;
    ll ans = 0;
    set<ll, std::greater<ll> > s, z;
    s.insert(0);
    z.insert(0);
    for(i = 0; i < mid; i++){
        //v[i]
        set<ll> t;
        for(auto it = s.begin(); it != s.end(); it++){
            t.insert((v[i]+(*it))%m );
        }
        for(auto it = t.begin(); it != t.end(); it++){
            s.insert((*it));
        }
    }
    for(i = mid; i < n; i++){
        //v[i]
        set<ll> t;
        for(auto it = z.begin(); it != z.end(); it++){
            t.insert((v[i]+(*it))%m );
        }
        for(auto it = t.begin(); it != t.end(); it++){
            z.insert((*it));
        }
    }
    for(auto it = z.begin(); it != z.end(); it++){
        //(*it)
        auto ptr = s.lower_bound( (m-(*it))-1 );
        //cout << (*it) << " ";
        if(ptr!=s.end()){
            ans = max(((*ptr)+(*it))%m, ans);
        }
        ans = max(ans, (*it));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();//ll t; cin>>t; while(t--){solve();}
    return 0;
}
