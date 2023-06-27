#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


//defines...
#define ll           long long
#define boost        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb           push_back
#define mp           make_pair
#define in           insert
#define pi           2*acos(0.0)
#define srt(s)       sort(s.begin(),s.end())
#define rsrt(s)      sort(s.rbegin(),s.rend())
#define all(x)       x.begin(),x.end()
#define mem(a, b)    memset(a, b, sizeof(a))
#define c_test       printf("Case %lld: ",t)

const ll mod=1e9+7;
const ll MX=2e5+5;


inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication

inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}


typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {x = 1;y = 0;return a;}
    ll x1, y1, d = ext_gcd(b, a % b, x1, y1);
    x = y1;y = x1 - y1 * (a / b);
    return d;
}

//code goes from here...



int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    int tc;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        int n;
        cin >> n;
        int mtx[2*n-1][n];
        ll sum[2*n-1][n];

        mem(mtx,0);
        mem(sum,0);


        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<=i;j++) 
            {
                cin >> mtx[i][j];
            }
        }
        ll shft=1;
        for(ll i=n;i<2*n-1;i++)
        {
            for(ll j=shft;j<n;j++)
            {
                cin >> mtx[i][j];
            }
            shft++;
        }

       
       sum[0][0]=mtx[0][0];

        for(ll i=1;i<n;i++)
        {
            for(ll j=0;j<=i;j++)
            {
                if(j==0)
                {
                    sum[i][j]=sum[i-1][j]+mtx[i][j];
                }
                else 
                {
                    sum[i][j]=max(sum[i-1][j],sum[i-1][j-1])+mtx[i][j];
                }
            }
        }

        shft=1;

        for(ll i=n;i<(2*n)-1;i++)
        {
            for(ll j=shft;j<n;j++)
            {
                sum[i][j]=max(sum[i-1][j],sum[i-1][j-1])+mtx[i][j];
            } 
            shft++;  
        }

        c_test;
        printf("%lld\n",sum[2*n-2][n-1]);

    }
    
    //---------------------------------
    
    return 0;
}