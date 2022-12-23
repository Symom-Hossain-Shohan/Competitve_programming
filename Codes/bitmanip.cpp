#include <algorithm>
#include<bits/stdc++.h>
#include <random>
#include <string>
#include <utility>
using namespace std;

typedef long long ll;

void get_ith_bit(int n, int pos)
{
	int mask = 1<<pos; 
	n = n & mask; 
	cout << ((n>0) ? 1 : 0 )<< endl;  
	return;
}

void clear_ith_bit(int &n, int pos)
{
	int musk = ~(1<<pos); 
	n = n & musk; 
	return;
}



void set_ith_bit(int &n, int pos)
{
	int musk = 1<<pos; 

	n = n | musk; 
	return;
}

void update_ith_bit(int &n, int pos, int v)
{
	clear_ith_bit(n, pos);
	if(v) set_ith_bit(n, pos); 
	return;
	
}

void clear_last_ith_bit(int &n, int pos)
{
	int musk = (-1<<pos); 
	n = n & musk; 
	return;
}

void binary_of_n(int n)
{
	string s; 
	while(n)
	{
		if(n & 1) s.push_back('1'); 
		else s.push_back('0'); 
		n = n>>1; 
	}
	reverse(s.begin(), s.end()); 
	cout << s << endl; 
	return;
}

void clear_range_bits(int &n, int i, int j)
{
	int musk = (-1<<(j+1)); 
	//binary_of_n(musk); 
	int b = (1<<i) - 1; 
	musk = musk | b; 
	n = n & musk; 
	return;
}

void replace_bits(int &n, int m, int i, int j)
{
	m = m << i; 
	clear_range_bits(n, i, j); 
	n = n | m;
	cout << n << endl;  
	return;
}
int count_bits(int n)
{
	int cnt = 0; 
	while(n)
	{
		n  = n & (n-1); 
		cnt++; 
	}
	return  cnt;
}

void solve()
{
    int n = (1<<9)-1;
    int m = 5; 
    binary_of_n(n); 
    //clear_ith_bit(n, 2) ;
    //set_ith_bit(n, 2) ;  
    //clear_last_ith_bit(n, 3); 
    //clear_range_bits(n, 3, 5) ; 
    //cout << n << endl;
    //replace_bits(n, m, 3, 5); 
    cout << count_bits(n) << endl; 
    cout << __builtin_popcount(n) << endl; 
    cout << __builtin_popcountll(n) << endl; 
    binary_of_n(n);  
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