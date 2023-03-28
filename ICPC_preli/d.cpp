#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, c , k; 
    cin >> a >> b >> c >> k; 

    ll sum = a+b+c; 
    if(sum%3!=0)
    {
        cout << "Fight\n";
    }
    else if(sum/3==a and a == b and a==c)
    {
        cout << "Peaceful\n";
    }
    else 
    {
        ll cnt = 0; 
        if(a>=k) cnt++; 
        if(b>=k) cnt++; 
        if(c>=k) cnt++;
        sum/=3;  
        if(cnt>=2 and abs(sum-a)%k==0 and abs(sum-b)%k==0 and abs(sum-c)%k==0)
        {
            cout << "Peaceful\n";
        }
        else cout << "Fight\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}