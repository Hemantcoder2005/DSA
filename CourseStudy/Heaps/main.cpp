#include <iostream>
#include <vector>

using namespace std;

class Heaps{
    public:
        //using -1 based indexing.
        vector<int> arr={-1};

    void MinHeapInsert(int val){
        
        //Step1: Inserting val at last
        arr.push_back(val);

        //Step2: Setting Index at last
        int index=arr.size()-1;
        while (index>1)
        {
            if(arr[index]<arr[index/2]){
                swap(arr[index],arr[index/2]);
                index/=2;
            }else{
                return;
            }
        }
        
    }
        void MaxHeapInsert(int val){
        
        arr.push_back(val);
        int index=arr.size()-1;
        while (index>1)
        {
            if(arr[index]>arr[index/2]){
                swap(arr[index],arr[index/2]);
                index/=2;
            }else{
                return;
            }
        }
        
    }
    void MinHeapDelete(){
        // we always delete first node
        
        //step1: making first node = last node
        arr[1]=arr[arr.size()-1];
        
        // Step2: erasing the lastnode
        arr.erase(arr.end()-1);

        //step3: Now putting first node on its correct position
        int index=1;
        while(index<arr.size()){
            int left=2*index;
            int right=2*index+1;

            if(left<arr.size() && arr[index]>arr[left]){
                swap(arr[left],arr[index]);
                index=left;
            }
            else if(right<arr.size() && arr[index]>arr[right]){
                swap(arr[right],arr[index]);
                index=right;
            }else{
                return;
            }
        }

    }
    void MaxHeapDelete(){
        // we always delete first node
        
        //step1: making first node = last node
        arr[1]=arr[arr.size()-1];
        
        // Step2: erasing the lastnode
        arr.erase(arr.end()-1);

        //step3: Now putting first node on its correct position
        int index=1;
        while(index<arr.size()){
            int left=2*index;
            int right=2*index+1;

            if(left<arr.size() && arr[index]<arr[left]){
                swap(arr[left],arr[index]);
                index=left;
            }
            else if(right<arr.size() && arr[index]<arr[right]){
                swap(arr[right],arr[index]);
                index=right;
            }else{
                return;
            }
        }

    }

    void print(){
        for (int i = 0; i < arr.size(); i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }

};

 
void MinHeapify(int arr[],int size,int index){
    int smallest= index;
    int left=smallest*2 ;
    int right=left+1;

    if(left<=size && arr[smallest]>arr[left]){
        smallest=left;
    }
    else if(right<=size && arr[smallest]>arr[right]){
        smallest=right;
    }

    if(smallest!=index){
        swap(arr[smallest],arr[index]);
        MinHeapify(arr,size,smallest);
    }
}

void MaxHeapify(int arr[],int size,int index){
    int largest= index;
    int left=2*index ;
    int right=2*index+1;

    if(left<=size && arr[largest]<arr[left]){
        largest=left;
    }
    else if(right<=size && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=index){
        swap(arr[largest],arr[index]);
        MaxHeapify(arr,size,largest);
    }
}
void printHeap(int arr[],int size){
    for (int i = 1; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main() {
    Heaps* mh=new Heaps();

    mh->MinHeapInsert(1);
    mh->MinHeapInsert(2);
    mh->MinHeapInsert(3);
    mh->MinHeapInsert(4);
    mh->MinHeapInsert(5);
    cout<<"Min heap = ";
    mh->print();
    mh->MinHeapDelete();
    cout<<"\nAfter deletion Min heap = ";
    mh->print();


    Heaps* max_heap=new Heaps();
    max_heap->MaxHeapInsert(4);
    max_heap->MaxHeapInsert(3);
    max_heap->MaxHeapInsert(2);
    max_heap->MaxHeapInsert(1);
    max_heap->MaxHeapInsert(0);
    cout<<"\nMin heap = ";
    max_heap->print();
    max_heap->MaxHeapDelete();
    cout<<"\nAfter deletion Max Heap = ";
    max_heap->print();

    //MinHeapify
    int arr[6]={-1,2,1,4,6,0}; 
    int size=5;

    // We can consider all leaf node as heap so we don't have to process it
    for (int i =(size+1)/2; i >0; i--)
    {
        MinHeapify(arr,size,i);
        
    }
    cout<<"\nMin Heapify = ";
    printHeap(arr,size+1);

     // We can consider all leaf node as heap so we don't have to process it
    for (int i = (size+1)/2; i >0; i--)
    {
        MaxHeapify(arr,size,i);
        
    }
    
    cout<<"\nMax Heapify = ";
    printHeap(arr,size+1);

    return 0;
}