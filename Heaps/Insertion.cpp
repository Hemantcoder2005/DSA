#include <iostream>

using namespace std;

class heap{

    public:
        int arr[100];
        int size=0;
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;

        while (index>1)
        {
            int parent=index/2;
            if(arr[index]>arr[parent]){
                swap(arr[index],arr[parent]);
                index=parent;
            }
        }
        
    }
    void print(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }
};
int main() {
    // Your code here
    heap a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);

    a.print();

    return 0;
}