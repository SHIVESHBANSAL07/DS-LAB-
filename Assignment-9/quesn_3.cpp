#include <bits/stdc++.h>
using namespace std;
struct DSU{
    int n; vector<int> p,r;
    DSU(int n=0):n(n),p(n+1),r(n+1){ for(int i=1;i<=n;i++) p[i]=i; }
    int find(int a){ return p[a]==a?a:p[a]=find(p[a]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    if(!(cin>>n>>m)) return 0;
    vector<tuple<int,int,int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edges.emplace_back(w,u,v);
    }
    sort(edges.begin(), edges.end());
    DSU d(n);
    long long total=0;
    vector<pair<int,int>> ans;
    for(auto &t:edges){
        int w,u,v; w=get<0>(t); u=get<1>(t); v=get<2>(t);
        if(d.unite(u,v)){ total+=w; ans.emplace_back(u,v); }
    }
    cout<<total<<"\n";
    for(auto &p:ans) cout<<p.first<<" "<<p.second<<"\n";
    return 0;
}
