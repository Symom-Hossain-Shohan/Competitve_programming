#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    double a, b; 
    scanf("%lf : %lf", &a, &b);
    //cout << a << ' ' << b << endl; 

    double l = 0, r = 800, n=100; 
    while(n--)
    {
        double L = (l+r)/2.0;
        double W = (L*b)/a; 
        double R = sqrt(L*L+W*W)/2.0; 
        double theta = acos((2*R*R-W*W)/(2*R*R)); 
        double S = R*theta; 

        if(2*(L+S)<400) l = L; 
        else r = L;  

    }

    cout << fixed << setprecision(6) << l << ' ' << (l*b)/a << endl; 
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}