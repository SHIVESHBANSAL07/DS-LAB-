#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g;
vector<int> vis;
void dfs(int u){
    vis[u]=1;
    cout<<u<<' ';
    for(int v:g[u]) if(!vis[v]) dfs(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n>>m)) return 0;
    g.assign(n+1, {});
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s;cin>>s;
    vis.assign(n+1,0);
    dfs(s);
    return 0;
}
