#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k; if(!(cin>>k)) return 0;
    vector<long long> vals(k);
    for(int i=0;i<k;i++) cin>>vals[i];
    unordered_set<long long> s;
    bool dup=false;
    for(int i=0;i<k;i++){
        if(vals[i]==-1) continue;
        if(s.count(vals[i])){ dup=true; break; }
        s.insert(vals[i]);
    }
    cout<<(dup? "Duplicates Found" : "No Duplicates")<<"\n";
    return 0;
}
