#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pairll pair<long long, long long>
#define db double
using namespace std;

void solve(){
    ll n, i, j, k;
    string s;
    cin >> n >> s;
    ll ans = 0;
    ll last = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            last = -2;
            for(k = j; k <= i; k++){
                if(s[k]=='1'){
                    if(abs(last-k)>1){
                        last = k+1;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll t; cin >> t; while(t--){solve();}
    return 0;
}
