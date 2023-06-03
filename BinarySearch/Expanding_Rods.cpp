#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    double L, n, c; 
    cin >> L >> n >> c; 
    double L_a = (1.0+(n*c))*L; 
    //cout << L_a << endl; 

    double low = 0.0, high = L; 
    for(int i=0;i<100; i++)
    {
        double b = (low+high)/2.0; 
        double c = L*0.5; 
        double r = b/2 + (c*c/(2*b));
        double a = 2*asin(c/r); 

        double s = r*a; 
        if(s<L_a) low = b; 
        else high = b; 
    }

    cout << fixed << setprecision(9) << low << endl; 

    
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