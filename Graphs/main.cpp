#include<iostream>
#include<unordered_map>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

class Graph{

	public:
		unordered_map<int,vector<int>> adj;
		
	void insert(int node1,int node2,bool directed){
	
		if(!directed){
		
			adj[node2].push_back(node1);
		}

		adj[node1].push_back(node2);
	}
	void print(){
		for(auto node:adj){
			cout<<node.first<<" --> ";

			for(auto inner_node:node.second){
				cout<<inner_node<<" ";
			
			}		

			cout<<"\n";
		}
	
	}

	void bfs(int node){
		queue<int>* q=new queue<int>();
		q->push(node);
		unordered_map<int,bool> visted;
		while(!q->empty()){
		
			int frontNode=q->front();
			q->pop();
			visted[frontNode]=true;
			cout<<frontNode<<" ";

			for(auto n:adj[frontNode]){
				
				if(!visted[n]){
					q->push(n);
					visted[n]=true;
				}	
			}

			

		}
	
	}

	

	void dfs(int node,unordered_map<int,bool> &visted){
			cout<<node<<" ";
			visted[node]=true;
		for(auto n:adj[node]){
			if(!visted[n]){
				dfs(n,visted);
		}
		}
	
	}

	void topological(int node, unordered_map<int,bool> &visted, stack<int>* &ans) {

        visted[node]=true;
        for(auto n:adj[node]){
            if(!visted[n]){
                topological(n,visted,ans);
            }
        }
        ans->push(node);


}
};

int main(){

	int nodes;
	cout<<"Enter Number of nodes = ";
	cin>>nodes;
	
	int edges;
	cout<<"Enter the number of edges = ";
	cin>>edges;
	

	bool directed;
	cout<<"Do want directed graph = (0/1)";
	cin>>directed;

	cout<<"let's insert\n";

	//creating graph instance
	Graph* g=new Graph();


	for(int i=0;i<edges;i++){
		int n1,n2;
		cin>>n1>>n2;
		g->insert(n1,n2,directed);
	
	}

	g->print();


	int node;
	cout<<"Enter the Base node"<<endl;
	cin>>node;
	cout<<"BFS = ";
	g->bfs(node);
	cout<<"\n";
	
	cout<<"DFS = ";
	unordered_map<int,bool> visted;
	g->dfs(node,visted);

	unordered_map<int,bool> vist;
	stack<int>* ans=new stack<int>();
	cout<<"\n";
	cout<<"TopologicalSort = ";
	g->topological(node,vist,ans);

	while (!ans->empty())
	{
		cout<<ans->top()<<" ";
		ans->pop();

	}
	
	
	return 0;
}
