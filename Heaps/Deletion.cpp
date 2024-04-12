#include <iostream>

using namespace std;

class heap{

    public:
        int arr[100];
        int size=0;


    void deletion(){
        if(size==0){
            cout<<"Heap is empty";
            return;
        }

        // making root node equal to last node
        arr[1]=arr[size];
        int index=1;
        size--;
        while(index<size){
            int leftIndex=2*index;
            int rightIndex=2*index;

            //left side
            if(leftIndex<size && arr[index]< arr[leftIndex]){
                swap(arr[index], arr[leftIndex]);
                index=leftIndex;
            }
             else if(rightIndex<size && arr[index]< arr[rightIndex]){
                swap(arr[index], arr[rightIndex]);
                index=rightIndex;
            }else{
                return;
            }
        }
        
    }
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
        cout<<endl;
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
    
    a.deletion();
    a.print();

    a.deletion();
    a.print();

    a.deletion();
    a.print();

    a.deletion();
    a.print();

    a.deletion();
    a.print();
    a.deletion();
    a.print();
    return 0;
}