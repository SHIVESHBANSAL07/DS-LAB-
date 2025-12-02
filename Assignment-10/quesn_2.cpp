#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n)) return 0;
    unordered_set<long long> sa;
    for(int i=0;i<n;i++){ long long x; cin>>x; sa.insert(x); }
    cin>>m;
    unordered_set<long long> out;
    vector<long long> order;
    for(int i=0;i<m;i++){
        long long x; cin>>x;
        if(sa.count(x) && !out.count(x)){ out.insert(x); order.push_back(x); }
    }
    for(size_t i=0;i<order.size();++i){
        if(i) cout<<" ";
        cout<<order[i];
    }
    cout<<"\n";
    return 0;
}
