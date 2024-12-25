#include<iostream>

using namespace std;


int countZeros(int n){
    if(n == 0) return 0;
    int temp = 0;
    if(n%10 == 0)temp=1;
    return temp + countZeros(n/10);

}


int main(){
    int ans = countZeros(30204);
    cout<<ans<<endl;
}