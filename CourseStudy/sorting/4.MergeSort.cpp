#include<iostream>

using namespace std;



void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Merge(int arr[],int low,int mid,int high){
	int i=low,k=0;
	int j=mid;
	int arrTemp[high-low+1];

	while (i<=mid && j<=high)
	{
		if(arr[i]>=arr[j]){
			arrTemp[k]=arr[j];
			j++;
		}
		else{
			arrTemp[k]=arr[i];
			i++;
		}
		k++;
		
	}
	while (i < mid) {
        arrTemp[k++] = arr[i++];
    }

    while (j <= high) {
        arrTemp[k++] = arr[j++];
    }

    // Copy the merged elements back to the original array
    for (int x = low; x <= high; x++) {
        arr[x] = arrTemp[x - low];
    }

	

}
void MergeSort(int arr[],int low,int high){
	if(low>=high){
		return;
	}
	int mid=(low+high)/2;

	// Spliting in left and right Part
	MergeSort(arr,low,mid);
	MergeSort(arr,mid+1,high);

	Merge(arr,low,mid+1,high);
}


int main(){

	 int size=5;
	 int arr[size]={5,4,3,2,1};

	 cout<<"Before Sorting : ";
	 print(arr,size);
	MergeSort(arr,0,size-1);
	 cout<<"After Sorting : ";
	 print(arr,size);   
        
    
               
                

}

