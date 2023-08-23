#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int arr[N]={0};

void insert(int num, int index){
    
    if(arr[index] == 0){
        cout<<index<<" ";
        
        arr[index]=num;cout<<arr[index]<<endl;
    }else if(arr[index]>num){
        
        insert(num, (index*2)+1);
    }else{
        insert(num, (index*2)+2);
    }
    
}
bool find(int num, int index){
    if(arr[index] == 0){
        return false;
    }
    if(arr[index] == num){
        return true;
    }
    if(arr[index]>num){
        find(num, (index*2)+1);
    }else{
        find(num, (index*2)+2);
    }
}

int main(){

    int n=7, a[n]={11,77,44,33,55,99,66};
    for (int i = 0; i < n-1; i++)
    {
        cout<<"insert: "<<a[i]<<endl;
        insert(a[i],0);
    }
    for (int i = 0; i < N; i++)
    {
        if(arr[i]){
            cout<<arr[i]<<" is at index "<<i+1<<endl;
        }
    }
     cin>> n;
    bool k = find(n,0);
    if(k){
        cout<<"found"<<endl;
    }else{
        cout<<"not found"<<endl;
    }
    
    
    
    return 0;
}