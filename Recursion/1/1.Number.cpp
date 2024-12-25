#include<iostream>

using namespace std;

void printNumber(int n){
    if (n<0)return;
    cout<<n<<endl;
    printNumber(--n);
}
int main(){
    int n = 10;
    printNumber(n);
}