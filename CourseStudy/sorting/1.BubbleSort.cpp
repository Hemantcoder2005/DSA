#include<iostream>

using namespace std;



void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void BubbleSort(int arr[],int size){
	for (int  i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
		
	}
	
}
int main(){

	 int size=5;
	 int arr[size]={5,4,3,2,1};

	 cout<<"before Sorting : ";
	 print(arr,size);
		BubbleSort(arr,size);
	 cout<<"before Sorting : ";
	 print(arr,size);   
    
	/*
	
	
		Bubble sort is a simple sorting algorithm that repeatedly steps through the list, 
		compares adjacent elements, and swaps them if they are in the 
		wrong order. This process is repeated until the entire list is sorted. 
		In the worst and average cases, bubble sort has a time complexity of O(n^2), making it inefficient for large lists.
		 However, it has a straightforward implementation and can be useful for sorting small lists or as an educational tool. In the best case, when the input array is already sorted, bubble sort still requires a full pass through the array, resulting in O(n^2) time complexity.
	
	*/

}

