#include <iostream>
#include <unordered_map>
#include <list>
#include<vector>
using namespace std;

#ifndef BUILD
#define BUILD
template <typename T>
class Graph{

    public:
        unordered_map<T,list<T>> adj;
    void insert(T u, T v,bool direction){
        // 0: It is undirected graph and 1:directed graph
        adj[u].push_back(v);
        if(direction){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for (auto &&i : adj)
        {
            cout<<i.first<<" --> ";
            for (auto &&j : i.second)
            {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        
    }
};

#endif
int main() {
    // Your code here
    Graph<int>* g=new Graph<int>;
    
    int n;
    cout<<"Enter Number of nodes = ";
    cin>>n;

    int e;
    cout<<"Enter the number of edges = ";
    cin>> e;

    bool direction;
    cout<<"Enter 0 for undirected graph or 1 for directed graph =  ";
    cin>>direction;

    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        g->insert(u,v,direction);
    }
    
    g->printAdjList();
    
    return 0;
}