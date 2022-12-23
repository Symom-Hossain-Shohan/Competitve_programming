#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >> s ;
    while(s.back()=='0') s.pop_back(); 
    reverse(s.begin(), s.end()) ; 
    while(s.back() == '0') s.pop_back(); 
    reverse(s.begin(), s.end());
    
    int total_zero = 0 ;
    for(int i=0;i<(int)s.size();i++) if(s[i] == '0') total_zero++ ;

    vector<pair<int,int>> L, R; 
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='0') continue;
        int j = i ;
        int one = 0, zero = 0;
        for(;j<(int)s.size();j++)
        {
            if(s[j]=='1') one++;
            else break;
        }
        for(;j<(int)s.size();j++)
        {
            if(s[j]=='0') zero++;
            else break;
        }

        L.push_back({one,zero}); 
        i = j-1;
    }

    for(int i = (int)s.size()-1; i>=0 ; i--)
    {
        if(s[i]=='0') continue; 
        int j = i;
        int one = 0 , zero =0 ;
        for(;j>=0;j--) 
        {
            if(s[j] == '1') one++;
            else break;
        }
        for(;j>=0;j--)
        {
            if(s[j] == '0') zero++;
            else break;
        }

        R.push_back({one, zero}); 
        i = j+1 ; 
    } 

    int one = 0 ; 
    for(int i = 0, j = (int)R.size()-1;i<j;)
    {
        if(total_zero<=one) break;
        int J = R.size()-j-1 ;

        if(L[i].second >= L[i].first and R[J].second >= R[J].first)
        {
            if(L[i].second> R[J].second)
            {
                one+= L[i].first;
                total_zero-= L[i].second;
                i++;
            }
            else if(R[J].second > L[i].second)
            {
                one += R[J].first;
                total_zero -= R[J].second;
                j--;
            }
            else 
            {
                if(L[i].first<=R[J].first)
                {
                    one += L[i].first; 
                    total_zero -= L[i].second; 
                    i++;
                }
                else 
                {
                    one += R[J].first; 
                    total_zero -= R[J].second;
                    j--;  
                }
            }
        } 
        else if(L[i].second >= L[i].first)
        {
            one += L[i].first ;
            total_zero -= L[i].second;
            i++;
        }
        else if(R[J].second >= R[J].first)
        {
            one += R[J].first ;
            total_zero -= R[J].second ;
            j--;
        }
        else break;
        
    }

    if(s.empty())  cout << 0 << endl; 
    else cout << max(one, total_zero) << endl; 
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