#include<iostream>

using namespace std;

void fn(int n){
    if (n<1)return;
    fn(n-1);
    cout<<n<<endl;

}


int main(){

    fn(5);
}