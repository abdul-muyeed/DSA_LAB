#include <bits/stdc++.h>
using namespace std;

int fac(long long int a){
    if(a==0 || a==1){
        return 1;
    }
    return a*fac(a-1);
}

int main(){
    int n;
    cin>>n;
    // Answer to the  question No.6

    cout<< fac(n);
    return 0;
}