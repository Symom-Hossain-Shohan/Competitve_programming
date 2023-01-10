#include <bits/stdc++.h>
using namespace std;

#define ll long long


void Merge(vector<ll> &L, vector<ll> &R, vector<ll> &v)
{
    int i=0, j=0, k=0;  
    while(i<(int)L.size() and j<(int)R.size())
    {
        if(L[i]<=R[j])
        {
            v[k] = L[i]; 
            k++, i++;  
            
        }
        else 
        {
            v[k] = R[j];  
            k++, j++;  
        }
        
    }
    while(i<(int)L.size())
    {
        v[k] = L[i]; 
        i++, k++; 
          
    }
    while(j<(int)R.size())
    {
        v[k] = R[j];  
        j++, k++;
        
    }
}

void mergesort(vector<ll> &v)
{
    ll n = v.size();
    if (n < 2)
    {
        //cnt++; 
         return;
    }
    ll m = n / 2;
    vector<ll> L(m), R(n - m);
    for (int i = 0; i < m; i++)
        L[i] = v[i];
    for (int i = m, j = 0; i < n; i++, j++)
        R[j] = v[i];
    
    mergesort(L); 
    mergesort(R); 
    Merge(L, R, v); 
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    mergesort(v);
    for(auto i: v) cout << i << ' '; 
    
}