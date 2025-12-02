#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    if(!(cin>>n>>m)) return 0;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int s;cin>>s;
    const int INF = 1e9;
    vector<int> key(n+1, INF), par(n+1,-1), vis(n+1,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    key[s]=0; pq.push({0,s});
    long long total=0;
    vector<pair<int,int>> mst;
    while(!pq.empty()){
        auto [w,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        total += w;
        if(par[u]!=-1) mst.emplace_back(par[u], u);
        for(auto &e:g[u]){
            int v=e.first, wt=e.second;
            if(!vis[v] && wt < key[v]){
                key[v]=wt;
                par[v]=u;
                pq.push({key[v], v});
            }
        }
    }
    cout<<total<<"\n";
    for(auto &e:mst) cout<<e.first<<" "<<e.second<<"\n";
    return 0;
}
