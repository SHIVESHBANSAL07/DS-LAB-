#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    unordered_set<long long> s;
    bool dup=false;
    for(int i=0;i<n;i++){
        long long x; cin>>x;
        if(s.count(x)) dup=true;
        s.insert(x);
    }
    cout<<(dup?"true":"false")<<"\n";
    return 0;
}
