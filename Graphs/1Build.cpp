#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

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
     for (const auto& pair : adj) {
        cout << pair.first << ": ";
        for (int i = 0; i < pair.second.size(); i++)
        {
            cout<<pair.second[i]<<" ";
        }
        cout<<endl;
        
    }
    

}