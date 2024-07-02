#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>
using namespace std;
void BFS(unordered_map<int,vector<int>> adj){
    //Assuming Starting Node to be first element of adj
    int node = adj.begin()->first;

    // Creating visting Array
    vector<bool> visted (adj.size()+1,0);

    // Marking first node to be visted
    visted[node] = true;

    // Creating a tracker Queue
    queue<int> tracker;

    //Pushing node to tracker
    tracker.push(node);

    // While whole graph is not traversed
    while (!tracker.empty())
    {
        // creating new Node storing from front of queue.
        int newNode = tracker.front();

        // Printing it out
        cout<<newNode<<" ";

        // poping out from front of a node
        tracker.pop();

        //pushing all node adjacent to newNode and not visted and marking them visted
        for (auto & n : adj[newNode])
        {
            if (!visted[n]) {
                tracker.push(n);
                visted[n] = true;
            }
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
     
    BFS(adj);

}