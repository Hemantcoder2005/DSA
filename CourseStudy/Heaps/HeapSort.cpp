#include <iostream>

using namespace std;

void heapify(int* arr,int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

}
int main() {
    // Your code here
    int arr[6]={-1,54,53,55,52,50};
    int size=(sizeof(arr)/sizeof(int));

    //Converting to heap
    for (int i =size; i >0 ; i--)
    {
        heapify(arr,size,i);
    }

    //sorting
    int tempSize=size-1;
    while (tempSize>1)
    {
        swap(arr[1],arr[tempSize]);
        tempSize--;
        heapify(arr,tempSize,1);
        
    }
    
    //printing
    for(auto x:arr){
        cout<<x<<" ";
    }
    
    return 0;
}