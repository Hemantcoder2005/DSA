#include <iostream>
using namespace std;

bool binarySearch(int* arr,int low,int high,int target){
	
	if(low>high){
		return false;
	}

	int mid=(high + low)/2;
	
	if (arr[mid]== target){
		return true;
	}else if(arr[mid]>target){	
		binarySearch(arr,low,mid-1,target);
	
	}else{
	binarySearch(arr,mid+1,high,target);
	}
}

int main(){

	int size=5;
	int arr[size]={1,2,3,4,5};
	
	int target;
	cout<<"Enter the targeted value to be searched = ";
	cin>>target;
	
	
	//Binary Search
	bool gotit=binarySearch(arr,0,size-1,target);
	if(gotit){
		cout<<"Got it";
	
	}

	else{
	
		cout<<"Didn't find that!";
	}

	return 0;
}
