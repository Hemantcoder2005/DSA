#include<iostream>

using namespace std;



void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void SelectionSort(int arr[],int size){
	for (int  i = 0; i < size; i++)
	{
		int min_index=i;
		for (int j = i; j < size; j++)
		{
			if(arr[min_index]>arr[j]){
				min_index=j;
			}
		}
		swap(arr[i],arr[min_index]);
		
	}
	
}
int main(){

	 int size=5;
	 int arr[size]={5,4,3,2,1};

	 cout<<"before Sorting : ";
	 print(arr,size);
     SelectionSort(arr,size);
	 cout<<"before Sorting : ";
	 print(arr,size);   
        
    
               
                

}

