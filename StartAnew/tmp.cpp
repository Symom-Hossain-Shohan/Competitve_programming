#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(s) s.begin(),s.end()
typedef long long ll;
const ll N=5e5+5,M=2000000381,H=139;


string a,b;
ll sz,mm[20][2][2][10][10],anss[30];
ll nxt[20][2][2][10][10];

ll rec(ll i,ll is_big,ll is_small,ll mx,ll mn)
{
    if(i>=sz){
        return mx-mn;
    }
    ll &ans=mm[i][is_big][is_small][mx][mn];
    if(ans!=-1)return ans;
    
    
    ans=10;
    ll aa=a[i]-'0';
    ll bb=b[i]-'0';
    ll high=aa,low=bb;
    
    if(is_big)low=0;
    if(is_small)high=9;
    
    for(ll j=low;j<=high;j++){
        ll x=rec(i+1,is_big|(j>bb),is_small|(j<aa),max(j,mx),min(j,mn));
        
        
        if(x<ans){
            ans=x;
            nxt[i][is_big][is_small][mx][mn]=j;
        }
    }
    return ans;
    
}
void pri(ll i,ll is_big,ll is_small,ll mx,ll mn)
{
    if(i>=sz){
        return ;
    }
    
    ll nx=nxt[i][is_big][is_small][mx][mn];
    cout<<nx;
    
    ll aa=a[i]-'0';
    ll bb=b[i]-'0';
    pri(i+1,is_big|(nx>bb),is_small|(nx<aa),max(nx,mx),min(nx,mn));
    return ;
}


void solve()
{
    ll lft,rgt;
    cin>>lft>>rgt;
    a=to_string(rgt);
    b=to_string(lft);
    
    if(a.size()!=b.size()){
        cout<<string(a.size()-1,'9')<<"\n";
        return ;
    }
    memset(mm,-1,sizeof mm);
    sz=a.size();
    memset(anss,-1,sizeof anss);
    rec(0,0,0,0,9);
    pri(0,0,0,0,9);
    cout<<"\n";

    
    
}

int main()
{
    fast;
  
    
    ll t=1,tc=1;
    cin>>tc;
    while(tc--){
        //cout<<"Case "<<t++<<": ";
        solve();//cout<<"\n";
       // cout.flush();
        //cout<<"\n";
    }
    return 0;
    
}