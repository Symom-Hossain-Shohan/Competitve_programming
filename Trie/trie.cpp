//************ || MD. SAJID ALAM CHOWDHURY || *************//
//**************** || 30-Nov-2022(Wed) || *****************//
//******************** || 13:51:42 || *********************//

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<functional>

using namespace std;
using namespace __gnu_pbds;

//********************* || DEFINES || *********************//
#define BOOST                      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff                         first
#define ss                         second
#define IN                         insert
#define MP                         make_pair
#define PB                         push_back
#define PF                         push_front
#define LB                         lower_bound
#define UB                         upper_bound
#define NP                         next_permutation
#define PP                         prev_permutation
#define all(v)                     v.begin(),v.end()
#define Fo(i,a,b)                  for(ll i=a;i<=b;i++)
#define Fb(i,b,a)                  for(ll i=b;i>=a;i--)
#define mem_0(arr)                 memset(arr,0,sizeof(arr))
#define mem_1(arr)                 memset(arr,-1,sizeof(arr))
#define precise_impact(x)          fixed<<showpoint<<setprecision(x)

//******************** || TYPEDEFS || *********************//
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pref_trie;

//******************** || CONSTANTS || ********************//
const ll MAX=2e5+5;
const ll MOD=1e9+7;    // 998244353 //
const ll INF=1e18+5;
const db PI=acos(-1);

//--------- Up-Down,Left-Right ---------//
//const ll dx[]={ 0, 0,-1, 1};
//const ll dy[]={-1, 1, 0, 0};
//------------ King's Moves ------------//
//const ll dx[]={ 0, 0,-1,-1,-1, 1, 1, 1};
//const ll dy[]={-1, 1, 0,-1, 1, 0,-1, 1};
//----------- Knight's Moves -----------//
//const ll dx[]={-2,-2,-1,-1, 1, 1, 2, 2};
//const ll dy[]={-1, 1,-2, 2,-2, 2,-1, 1};

//***************** || INLINE FUNCTIONS || ****************//
inline ll norm(ll &a) { a%=MOD; return (a<0)?(a+=MOD):a; }
inline ll modAdd(ll a,ll b) { a%=MOD,b%=MOD; norm(a),norm(b); a+=b; return norm(a); }
inline ll modSub(ll a,ll b) { a%=MOD,b%=MOD; norm(a),norm(b); a-=b; return norm(a); }
inline ll modMul(ll a,ll b) { a%=MOD,b%=MOD; norm(a),norm(b); a*=b; return norm(a); }
inline ll modPow(ll a,ll p) { ll c=1; while(p){ if(p%2){ c=modMul(c,a); } a=modMul(a,a); p/=2; } return c; }
inline ll modInverse( ll a) { return modPow(a,MOD-2); }
inline ll modDiv(ll a,ll b) { a%=MOD,b%=MOD; norm(a),norm(b); return modMul(a,modInverse(b)); }

//******************** || FUNCTIONS || ********************//
ll gcd(ll m,ll n)
{
    while(n!=0)
    {
        m%=n;
        swap(m,n);
    }
    return m;
}

ll lcm(ll m,ll n)
{
    return ((m*n)/gcd(m,n));
}

ll bit_on(ll pos,ll mask)
{
    return mask|(1<<pos);
}

bool bit_check(ll pos,ll mask)
{
    return mask&(1<<pos);
}

class Trie
{
  public:
    
    bool endmark;
    Trie *next[26];

    Trie()
    {
        endmark=false;
        Fo(i,0,25)
        {
            this->next[i]=NULL;
        }
    }

    void Insert(Trie *root,string s);

    bool Search(Trie *root,string s);

    void Delete(Trie *curr);

};

void Trie::Insert(Trie *root,string s)
{
    Trie *temp=root;
    Fo(i,0,s.size()-1)
    {
        if(temp->next[s[i]-'a']==NULL)
        {
            temp->next[s[i]-'a']=new Trie();
        }
        temp=temp->next[s[i]-'a'];
    }
    temp->endmark=true;
}

bool Trie::Search(Trie *root,string s)
{
    Trie *temp=root;
    Fo(i,0,s.size()-1)
    {
        if(temp->next[s[i]-'a']==NULL)
        {
            return false;
        }
        temp=temp->next[s[i]-'a'];
    }
    return temp->endmark;
}

void Trie::Delete(Trie *curr)
{
    Fo(i,0,25)
    {
        if(curr->next[i])
        {
            Delete(curr->next[i]);
        }
    }
    delete(curr);
}


int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    
    /***********************/ BOOST /***********************/

    //***************** || READY TO GO || *****************//

    Trie *root=new Trie();

    ll n;
    cin>>n;
    Fo(i,0,n-1)
    {
        string s;
        cin>>s;
        root->Insert(root,s);
    }
    ll q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        if(root->Search(root,s))
        {
            cout<<"Found"<<endl;
        }
        else
        {
            cout<<"Not Found"<<endl;
        }
    }

    root->Delete(root);
    
    return 0;
    
    //*************** || DONE AND DUSTED || ***************//
}