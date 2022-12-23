#include<bits/stdc++.h>
using namespace std ;
#include <iostream>
#include <map>
#include <algorithm>

map<int,int> m ; 

void solve()
{
    
 
    auto pr = std::max_element(m.begin(), m.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;
                });
 
    std::cout << pr->first << std::endl;        // four
}
 
int main()
{
    solve();
 
    return 0;
}

