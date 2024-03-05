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

	for(int i=0;i<size;i++){
		int MinIndex=i;
				for(int j=i+1;j<size;j++){

				if (arr[j]<arr[MinIndex]){
					MinIndex=j;
							}
}
	swap(arr[i],arr[MinIndex]);


	}

cout<<"After Sorting = ";
printArray(arr,size);

	return 0;}
