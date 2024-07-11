#include <bits/stdc++.h>
#define ll long long
#define ull long long
#define pairll pair<long long, long long>
#define db double
#define MOD 1000000007
#define MAXN 1004
using namespace std;

void solve(){
    ll n, i, j, k;
    cin >> n >> k;
    vector<ll> v(n);
    vector<pairll> vl = {}, vr = {};
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    ll cnt = 0, m = 0;
    for(i = k; i < n; i++){
        if(cnt>0 and v[i]<0){
            vr.push_back({cnt, m});
            cnt = 0;
            m = 0;
        }
        cnt+=v[i];
        m = min(m, cnt);
        if(i==n-1){
            vr.push_back({cnt, m});
        }
    }
    cnt = 0, m = 0;
    for(i = k-2; i >= 0; i--){
        if(cnt>0 and v[i]<0){
            vl.push_back({cnt, m});
            cnt = 0;
            m = 0;
        }
        cnt+=v[i];
        m = min(m, cnt);
        if(i==0){
            vl.push_back({cnt, m});
        }
    }
    /*for(i = 0; i < vl.size(); i++){
        cout << vl[i].first << " " << vl[i].second << "   ";
    }cout << endl;
    for(i = 0; i < vr.size(); i++){
        cout << vr[i].first << " " << vr[i].second << "   ";
    }cout << endl;*/
    cnt = v[k-1];
    ll l = 0, r = 0;
    if(l==vl.size() || r==vr.size()){cout << "YES" << endl; return;}
    while(true){
        ll a = l, b = r;
        while( (l+1==vl.size() || vl[l].first>0) && vl[l].second+cnt>=0){
            cnt += vl[l].first;
            l++;
            if(l==vl.size()){cout << "YES" << endl; return;}
        }
        while( (r+1==vr.size() || vr[r].first>0) && vr[r].second+cnt>=0){
            cnt += vr[r].first;
            r++;
            if(r==vr.size()){cout << "YES" << endl; return;}
        }
        if(a==l && b==r){cout << "NO" << endl; return;}
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t; cin >> t; while(t--){solve();}
    return 0;
}
