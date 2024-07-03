#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
void DFS(int node,unordered_map<int,vector<int>> adj,vector<bool> &visted){
    cout<<node<<" ";
    visted[node] = true;
   for(auto & newNode:adj[node])
    {
        if (!visted[newNode]) {
            DFS(newNode,adj,visted);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    bool undirected;cin>>undirected;
    unordered_map<int,vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        if(undirected) adj[v].push_back(u);
    }
    vector<bool> visted(n,0);
    int numberOfProvinces = 0;
    for(auto &node:adj){
        if(!visted[node.first]){
                DFS(node.first,adj,visted);
                numberOfProvinces++;
            }
    }
    cout<<numberOfProvinces<<endl;
}

#include<iostream>
using namespace std;

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
    return 0;
}