#include<iostream>
using namespace std;

void printArray(int* arr,int size){
	for(int i=0; i<size;i++){
	
		cout<<arr[i]<<" "; 
	}

}

int main(){
	int size=5;
	int arr[size]={5,4,3,2,1};
	
	cout<<"Before Sorting = ";
	printArray(arr,size);

	//Insertion Sort
	for(int i=0;i<size;i++){
	
	for(int j=i;j>0;j--){
		if(arr[j]<arr[j-1]){
		swap(arr[j],arr[j-1]);
		}
	}
	}


	cout<<"After Sorting = ";
	printArray(arr,size);

	return 0;


}
