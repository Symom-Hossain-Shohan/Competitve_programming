#include <algorithm>
#include<bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

bool is_vowel(char c)
{
	if(c =='a' or c == 'e' or c =='i' or c== 'o' or c=='u') return  true;
	else return  false;
}

void solve()
{
    ll n; 
    cin>> n;
    string s, start, end; 
    cin >> s; 
    vector<ll> pos; 
    pos.push_back(-1);
    for(int i=0;i<n;i++)
    {
    	if(i==0) 
    	{
    		pos.push_back(i); 
    		continue;
    	}
    	if(is_vowel(s[i])) pos.push_back(i); 
    }
    pos.push_back(n); 

    for(int i=(int)pos.size()-2, j=1;i>0;i--,j++)
    {
    	if(j%2==1)
    	{
    		for(int k = pos[i+1]-1;k>=pos[i]; k--) end.push_back(s[k]); 
    	}
    	else 
    	{
    		for(int k = pos[i+1]-1; k>=pos[i];k--) start.push_back(s[k]);
    	}
    }
    reverse(end.begin(), end.end()); 
    cout << start << end << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}