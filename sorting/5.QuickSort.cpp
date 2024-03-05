#include<iostream>

using namespace std;



void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int movePivot(int arr[],int low,int high){
	int partition_index=low;
	int i=low;
	int j=high;
	while(i<=j){
		if(arr[i]<=arr[partition_index]){
			i++;
		}
		else if(arr[i]>arr[partition_index] && arr[i]>arr[j]){
			swap(arr[i],arr[j]);
		}
		else{
			j--;
		}
	}

	swap(arr[partition_index],arr[j]);
	return j;
}
void QuickSort(int arr[],int low,int high){
	//Base Case
	if(low>=high){
		return;
	}
	int partition= movePivot(arr,low,high)	;
	QuickSort(arr,low,partition-1);
	QuickSort(arr,partition+1,high);
}
int main(){

	 int size=5;
	 int arr[size]={5,4,3,2,1};

	 cout<<"Before Sorting : ";
	 print(arr,size);
	 
	 QuickSort(arr,0,size-1);
	 
	 cout<<"After Sorting : ";
	 print(arr,size);   
        
    
               
                

}

