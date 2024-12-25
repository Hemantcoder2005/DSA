#include<iostream>
using namespace std;

int bs(int arr[],int s,int e,int target){
    if(s>e)return -1;
    int mid = (s+e)/2;
    if(arr[mid] == target)return mid;
    if(arr[mid] > target)return bs(arr,s,mid-1,target);
    return bs(arr,mid+1,e,target);
}


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout<<bs(arr,0,9,11)<<endl;


}