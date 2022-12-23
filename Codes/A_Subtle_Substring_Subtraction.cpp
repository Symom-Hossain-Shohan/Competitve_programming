#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s ;
    cin >> s ;
    if(s.size()%2)
    {
        ll  a = 0 , b= 0 ; 
        ll cnt1=0, cnt2=0;
        for(int i=0;i<(int)s.size()-1;i++)
        {
            cnt1+=s[i]-'a'+1;
        }

        for(int i=1;i<(int)s.size();i++)
        {
            cnt2+=s[i]-'a'+1;
        }
        if(cnt1>=cnt2)
        {
            a = cnt1; 
            b=s.back()-'a'+1;
        }
        else 
        {
            a = cnt2 ; 
            b=s[0]-'a'+1;
        }
        if(a>=b) cout << "Alice " << a-b<< endl; 
        else cout << "Bob " << b-a << endl;
    }
    else 
    {
        int a =0 ;
        for(int i=0;i<(int)s.size();i++) a+=s[i]-'a'+1; 
        cout << "Alice " << a << endl ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}