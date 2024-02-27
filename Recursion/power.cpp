#include <iostream>

using namespace std;

int pow(int a,int n){

    if(n==0){
        return 1;
    }
    else if (n%2==0){
        int half_pow=pow(a,n/2);
        return half_pow*half_pow;
    }
    else{
        int half_pow=pow(a,(n-1)/2);
        return a*half_pow*half_pow;
    }

}
int main() {
    // Your code here
    int a=5;
    int n=3;
    int ans=pow(a,n);

    cout<<ans<<endl;
    return 0;
}