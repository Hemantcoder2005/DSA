#include<iostream>
using namespace std;

int reverseNum(int n,int &base){
    if (n<=0) return 0;
    int num = reverseNum(n/10,base);
    int ans = (n%10)*base;
    base*=10;
    return num+ ans;
    
}   


int main(){
    int n = 12424;
    int base = 1;
    cout<<reverseNum(n,base)<<endl;
}