#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ncr[51][51]; 

void solve()
{
    ll n, a, b; 
    cin >> n >> a >> b; 
    for(int i=0;i<=n;i++)
    {
        for(int j=0; j<=i; ++j){
            if(j == 0 || j == i){
                ncr[i][j] = 1LL;
            } else {
                ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]);
            }
        }
    }

    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 

    sort(v.rbegin(), v.rend()); 
    double avg = 0; 
    for(int i=0;i<a;i++) avg += v[i]; 

    ll total_ath_element = 0, ath_elemet = 0; 
    for(int i=0;i<n;i++)
    {
        if(v[i]==v[a-1])
        {
            total_ath_element++; 
            if(i<a) ath_elemet++; 
        }
    } 

    ll cnt = 0; 
    if(ath_elemet==a)
    {
        for(int i=ath_elemet; i<=min(b, total_ath_element); i++)
        {
            cnt += ncr[total_ath_element][i]; 
        }
    }
    else cnt = ncr[total_ath_element][ath_elemet]; 

    cout << setprecision(20) << avg/a << endl << cnt << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;


    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}