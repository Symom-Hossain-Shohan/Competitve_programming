#include <bits/stdc++.h>

using namespace std;

string word;
long long dp[100][100];


long long calculate(int s, int e){

  // base cases
  // invalid index
    if(s > e) 
        return 0;

   // pointing at the same position
    if(s == e ) 
        return 1;

    // already calculated
    if(dp[s][e] != -1) 
        return dp[s][e];

    // when the charaters match
    if(word[s] == word[e]) 
        return dp[s][e] = 1 +  calculate(s+1, e) + calculate(s, e-1);
    // when the characters are unique
    else 
        return dp[s][e] = calculate(s+1, e) + calculate(s, e-1) - calculate(s+1, e-1);

}


int main(){
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; ++t){
        cout<<"Case "<<t<<": ";
        cin>>word;

        memset(dp, -1, sizeof dp);

        cout<<calculate(0,word.size()-1)<<endl;
    }
    return 0;
}