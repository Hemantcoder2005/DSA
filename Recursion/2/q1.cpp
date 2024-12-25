#include<iostream>
using namespace std;

void fn(int n){
    if(n<=0)return;
    cout<<n<<endl;
    fn(--n);
}


int main(){
    fn(5);
}