#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    unordered_map<long long,int> cnt;
    vector<long long> order;
    for(int i=0;i<n;i++){
        long long x; cin>>x;
        if(!cnt.count(x)) order.push_back(x);
        cnt[x]++;
    }
    for(long long v:order){
        cout<<v<<" -> "<<cnt[v]<<" "<<(cnt[v]==1?"time":"times")<<"\n";
    }
    return 0;
}
