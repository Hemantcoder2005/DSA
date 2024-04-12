#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Your code here
    priority_queue<int> pq;

    int arr[5]={3,2,1,34,2};

    for (int i = 0; i < 5; i++)
    {
        pq.push(arr[i]);
    }

    
    // priority queue uses max heap functionality by default
    cout<<"Max Heap\n";
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    
    
    // to use min heap
    cout<<"Min heap\n";
    priority_queue<int,vector<int>,greater<int>> minheap;

    for (int i = 0; i < 5; i++)
    {
        minheap.push(arr[i]);
    }
    cout<<minheap.top()<<endl;
    minheap.pop();
    cout<<minheap.top()<<endl;
    return 0;
}