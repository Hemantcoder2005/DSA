#include<iostream>

using namespace std;
void printArray(int* arr,int size)
{
for(int i=0;i<size;i++){
cout<<arr[i]<<" ";

}

}
int main(){
	int size=5;
	int arr[size]={5,4,3,2,1};
	

	cout<<"Before Sorting = ";
	printArray(arr,size);

	//BubbleSort
	for(int i=0;i<size;i++){
	for(int j=0;j<size-i;j++){
	
		if(arr[j]>arr[j+1]){
		   swap(arr[j],arr[j+1]);
		}
	}
	
	
	
	}
	cout<<endl<<"After Sorting = ";
	printArray(arr,size);

}
