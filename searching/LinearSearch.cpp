#include<iostream>
using namespace std;

int main(){

	int size=5;
	int arr[size]={5,4,3,2,1};

	int target;
	cout<<"Enter the Target value to be searched = ";
	cin>>target;


	for(int i=0;i<size;i++){
	
		if (arr[i]==target){
			cout<<"Found at "<<i<<" index number"<<endl;
			return 0;
		}
	}
	cout<<"Targeted Value Not found!";
	
}
