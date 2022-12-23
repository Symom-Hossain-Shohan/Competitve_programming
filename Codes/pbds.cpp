#include<bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;

void solve()
{
    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    double d, v;
    cin >> d >> v;
    string t;
    cin >> t ;
    double ta = (t[0] - '0') * 10 + (t[1] - '0');
    double tb = (t[3] - '0') * 10 + (t[4] - '0');
    double dtime = ta * 60 + tb - 9 * 60 ;
    cin >> t;
    double w;
    cin  >> w;
    ta = (t[0] - '0') * 10 + (t[1] - '0');
    tb = (t[3] - '0') * 10 + (t[4] - '0');
    dtime += ta * 60 + tb;
    dtime /= 60;
    //cout << dtime << endl;

    //atime
    double atime = 0;
    double dist = (xa - xc) * (xa - xc) + (ya - yc) * (ya - yc);
    dist = sqrt(dist);
    atime += (dist) / v + d / 60;

    dist = (xc - xb) * (xc - xb) + (yc - yb) * (yc - yb);
    dist = sqrt(dist);
    atime += dist / v;
    //cout << atime << endl;

    //ptime
    dist = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
    dist = sqrt(dist);

    double ptime = dist / w;
    if (xa <= xc and xc <= xb and ya <= yc and yc <= yb) ptime += d / 60;
    //cout << atime << ' ' << dtime << ' ' << ptime << endl;
    atime *= 3600;
    dtime *= 3600;
    ptime *= 3600;
    atime = ceil(atime);
    dtime = ceil(dtime);
    ptime = ceil(ptime);
    if (atime < dtime and atime < ptime) cout << "Alex\n";
    //if((ditme-atime)<=1e-6 and (dtime-atime)>0 and atime)
    else if (dtime < atime and dtime < ptime) cout << "Dmitry\n";
    else cout << "Petr\n";
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