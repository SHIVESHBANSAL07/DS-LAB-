#include <bits/stdc++.h>
using namespace std;
struct Node{ long long val; Node* next; Node(long long v):val(v),next(nullptr){} };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<Node*> nodes; nodes.reserve(n);
    for(int i=0;i<n;i++){ long long v; cin>>v; nodes.push_back(new Node(v)); if(i) nodes[i-1]->next = nodes[i]; }
    int pos; cin>>pos;
    if(n>0 && pos>=0 && pos<n) nodes.back()->next = nodes[pos];
    unordered_set<Node*> seen;
    Node* cur = n?nodes[0]:nullptr;
    bool cycle = false;
    while(cur){
        if(seen.count(cur)){ cycle=true; break; }
        seen.insert(cur);
        cur = cur->next;
    }
    cout<<(cycle?"true":"false")<<"\n";
    return 0;
}
