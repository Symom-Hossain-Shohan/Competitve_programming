#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string base = "BSUIROPENX";
    int n, m = base.length(); cin >> n;
    map<string, ll>ase, lagbe;
    string ss[n];
    for(int i = 0; i < n; i += 1){
        string s; cin >> s;
        ss[i] = s;
        int k = 0;
        bool ok = 1;
        for(; k < s.length(); k += 1){
            if(s[k] != base[k]){
                ok = 0; break;
            }
        }

        if(!ok){
            ok = 1;
            for(int k = m - 1, kk = s.length() - 1; kk  >= 0; k -= 1, kk -= 1){
                if(s[kk] != base[k]){
                    ok = 0; break;
                }
            }
        }

        if(ok)
            ase[s] += 1;
    }

    ll ans = 0;
    for(int i = 0; i < n; i += 1){
        if(ase[ss[i]]){
            string need = "";
            int l, r;
            if(ss[i][0] == 'B'){
                l = ss[i].length(); r = m;
            }
            else{
                r = m - ss[i].length(); l = 0;
            }

            for(; l < r; l += 1){
                need += base[l];
            }

            ans += (ase[need]*ase[ss[i]]);
            ase[need] = 0; ase[ss[i]] = 0;
        }

    }

    cout << ans << '\n';
}

int main(void){
    int t = 1;
    while(t--)
        solve();
}