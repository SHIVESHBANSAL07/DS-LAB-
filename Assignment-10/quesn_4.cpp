#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n);
    unordered_map<long long,int> cnt;
    for(int i=0;i<n;i++){ cin>>a[i]; cnt[a[i]]++; }
    for(int i=0;i<n;i++) if(cnt[a[i]]==1){ cout<<a[i]<<"\n"; return 0; }
    cout<<"-1\n";
    return 0;
}
