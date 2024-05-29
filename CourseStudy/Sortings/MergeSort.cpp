#include<iostream>
using namespace std;

void printArray(int* arr,int size){

	for(int i=0;i<size;i++){
	
		cout<<arr[i]<<" ";
	}
}



void merge(int* arr,int low,int mid,int high){
	int i=0;
	int j=mid+1;
	int k=0;
	int Tarr[high+1];
	while(i<=mid && j<=high){
		if(arr[i]>=arr[j]){
			Tarr[k]=arr[j];
			j++;
		}
		else{
			Tarr[k]=arr[i];
			i++;
		}
		k++;

	}
	//Adding all elements if data is left to be copied
	while(i<=low){
	
		Tarr[k]=arr[i];
		i++;
		k++;
	
	}


	while(j<=high){
	
		Tarr[k]=arr[j];
		j++;
		k++;
	}

	for(int i=0; i<=high;i++){
		arr[i]=Tarr[i];
	}

}
void mergeSort(int* arr,int low,int high){

	if(low>=high){
		return;
	}
	int mid=(low+high)/2;

	mergeSort(arr,0,mid);
	mergeSort(arr,mid+1,high);

	merge(arr,low,mid,high);


}

int main(){

	int size=5;
	int arr[size]={5,1,2,100,32};

	cout<<"Before Sorting = ";
	printArray(arr,size);

	mergeSort(arr,0,5);


	cout<<endl<<"After Sorting = ";
        printArray(arr,size);


}
