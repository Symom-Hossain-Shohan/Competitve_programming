#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string s;
ll B,S,C;
ll na, nb ,nc, pa, pb, pc, tk;

bool good(ll m)
{
    ll Na, Nb, Nc;
    Na=m*B ;
    Nb=m*S;
    Nc=m*C ;
    Na-=na ;
    Nb-=nb;
    Nc-=nc;
    return (max(0ll,Na)*pa+max(0ll,Nb)*pb+max(0ll,Nc)*pc)<=tk;
}


void solve()
{
    cin >> s;
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='B') B++;
        else if(s[i]=='S') S++;
        else C++;
    }

    cin >> na >>  nb >> nc; 
    cin >> pa >> pb >> pc;
    cin >> tk;

    ll l=0,r=100000000000000;
    while(r>l+1)
    {
        ll m=(l+r)/2;
        if(good(m)) l=m;
        else r=m;
    }
    cout << l << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}