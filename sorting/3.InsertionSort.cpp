#include<iostream>

using namespace std;



void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void InsertionSort(int arr[],int size){
	for (int  i = 0; i < size; i++)
	{
		for(int j=i;j>0;j--){
			if(arr[j]<arr[j-1]){
				swap(arr[j],arr[j-1]);
			}
		}
		
	}
	
}	
int main(){

	 int size=5;
	 int arr[size]={5,4,3,2,1};

	 cout<<"before Sorting : ";
	 print(arr,size);
	InsertionSort(arr,size);
	 cout<<"before Sorting : ";
	 print(arr,size);   
        
    
               
                

}

