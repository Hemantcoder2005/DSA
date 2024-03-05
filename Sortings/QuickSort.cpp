#include<iostream>
using namespace std;

void printArray(int* arr,int size){
	for(int i=0; i<size;i++){
		cout<<arr[i]<<" ";
	}

}

int movePivot(int* arr,int low,int high){

	//We are making pivot to low position
	int pivot=low;

	int i=low+1;
	int j=high;

	while(i<=j){
		
		if(arr[pivot]>=arr[i]){
			i++;
		}
		else if(arr[pivot]<arr[j]){
			j--;
		}
		else{
		
			swap(arr[i],arr[j]);
			i++;
			j--;
		}

	
	}

	//Swapping Pivot with j 
	swap(arr[pivot],arr[j]);
	return j;
}

void quickSort(int* arr,int low,int high){

	//Base Case
	if(low>=high){
		return;
	}

	int partition=movePivot(arr,low,high);
	quickSort(arr,low,partition-1);
	quickSort(arr,partition+1,high);

}

int main(){
	int size=5;
	int arr[size]={5,4,3,2,1};

	cout<<"Before Sorting = ";
	printArray(arr,size);


	//QuickSort
	quickSort(arr,0,size-1);

	cout<<"After Sorting = ";
	printArray(arr,size);

	return 0;

}
