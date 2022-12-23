#include<bits/stdc++.h>

using namespace std;

//defines...






#define mx 1000008
long long n,lazy[mx*4],tree[4*mx],a[mx];
void build(long long node,long long l,long long r)
{
	if(l==r)
	{
		tree[node]=a[l];
		return;
	}
	long long mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}
void update(long long node,long long b,long long e,long long l,long long r,long long v)
{
	// tree[node]+=lazy[node];
	// if(lazy[node]!=0)
	// {
	// 	lazy[node*2]+=lazy[node];
	// 	lazy[node*2+1]+=lazy[node];
	// }
	// lazy[node]=0;
	// if(l>e||r<b)
	// 	return;
	// if(l<=b&&r>=e)
	// {
	// 	tree[node]+=v;
	// 	lazy[node*2]+=v;
	// 	lazy[node*2+1]+=v;
	// 	return;
		
	// }
	// long long mid=(l+r)/2;
	// update(node*2,b,mid,l,r,v);
	// update(node*2+1,mid+1,e,l,r,v);
	// tree[node]=min(tree[node*2],tree[node*2+1]);
    //cout << "Updated\n" ;

    if(lazy[node]!=0)
    {
        long long  p = lazy[node] ; 
        lazy[node]=0 ; 
        tree[node]+= p ; 
        if(b!=e)
        {
            lazy[2*node] += p ; 
            lazy[2*node+1]+=p;
        }
    }

    if(l>e or r<b) return ; 
    if(l<=b and r>=b)
    {
        tree[node]+= v; 
        if(b!=e)
        {
            lazy[node*2]+=v ;
            lazy[2*node+1]+=v; 
        }
        return ;
    }

    update(2*node, b, (b+e)/2, l, r, v) ;
    update(2*node+1, (b+e)/2+1, e, l, r, v) ; 
    tree[node] = min(tree[2*node], tree[2*node+1]) ;


}
long long query(long long node,long long b,long long e,long long i,long long j)
{
	//cout<<"PP"<<endl;
	// tree[node]+=lazy[node];
	// if(lazy[node]!=0)
	// {
	// 	if(b!=e)
    //     {
    //         lazy[node*2]+=lazy[node];
	// 	    lazy[node*2+1]+=lazy[node];
    //     }
	// }
	//lazy[node]=0;
	// if(l>e||r<b)
	// 	return 1e18;
	// if(l<=b&&r>=e)
	// {
	// 	return tree[node];
		
	// }
	// long long mid=(l+r)/2;

	// long long t1=query(node*2,b,mid,l,r);
	// long long t2=query(node*2+1,mid+1,e,l,r);
	// tree[node]=min(tree[node*2],tree[node*2+1]);
	
	// return min(t1,t2);

    // cout << "query\n" ;
    // return 0 ; 

    if(i>e or j<b) return 1e18; 
    if(i<=b and j>=e)
    {
        return tree[node] ;
    }
 
    int left = 2*node ; 
    int right = 2*node + 1 ;
    int mid = (b+e)/2 ; 
 
    return min(query(left, b, mid, i, j) , query(right, mid+1, e, i, j)) ;
}
void oka()
{
	cin>>n;
	//yes
	long long i,j,k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	build(1,1,n);
	
	long long m;
	cin>>m;

    
	
	
	while(m--)
	{
		//yes

		long long l,r;
		char c;
		
        vector<long long>v;
        scanf("%lld%lld",&l,&r);
		
		v.push_back(++l);
		v.push_back(++r);
		scanf("%c",&c);
		if(c==' ')
		{
			long long p;
			cin>>p;
			v.push_back(p);
		}
		
		
		if(v.size()>2)
		{
			if(v[0]>v[1])
			{
				update(1,1,n,v[0],n,v[2]);
				update(1,1,n,1,v[1],v[2]);
			}
			else
			{
				update(1,1,n,v[0],v[1],v[2]);
			}
		}
		else
		{
			if(v[0]>v[1])
			{
				long long t1=query(1,1,n,v[0],n);
				long long t2=query(1,1,n,1,v[1]);
				cout<<min(t1,t2)<<endl;
			}
			else
			{
				cout<<query(1,1,n,v[0],v[1]);
			}
		}
		

	}
	




	
	
	



	
	










	
	
	






	

}

int main()
{
//#ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);

   // freopen("output.txt", "w", stdout);
//#endif

   // run

    long long t=1,i,j,k;
	long long ans=1;
	
	

	//cin>>t;
	
 	char c;
	
	 
 


  while(t--){
	//  cout<<"Case "<<ans++<<": ";
	 
 

	oka();


  }
}