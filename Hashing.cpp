#include <bits/stdc++.h>
using namespace std;
const int N=11;
int arr[N]={0};
struct node {
	int data;
	node* next;
};
node* head[N] = {NULL};
void insert(node* &head, int s) {
	node* temp = new node;
	temp->data = s;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		return;
	}
	node* temp1 = head;
	while (temp1->next != NULL) {
		temp1 = temp1->next;
	}
	temp1->next = temp;
}
void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int pow10(int n){
    int sum=1;
    for (int i = 0; i < n; i++)
    {
        sum = sum * 10;
    }
    return sum;
}
int reminder_methord(int a){
    return a%N;
}
int folding_methord(int a){
    int sum=0,temp = a;
    while (temp)
    {
        sum = sum + (temp%100);
        temp = temp/100;
    }
    a = sum;
    
    return a%N;
}
int midsqare_methord(int a){
    int temp = a,c=0;
    while (temp)
    {
        temp = temp/10;
        c++;
    }
    temp=a;
    if(c&1){
        temp = temp/pow10(c/2);
        a = temp%10;
    }else{
        temp = temp/pow10((c/2)-1);
        a = temp%100;
    }
    



    return a%N;
    
}
int linear_prod(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        int index = reminder_methord(a[i]);
        //int index = folding_methord(a[i]);
        //int index = midsqare_methord(a[i]);
        if(arr[index] == 0){
            arr[index] = a[i];
        }else{
            while(arr[index] != 0){
                index = (index+1)%N;
            }
            arr[index] = a[i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout<<arr[i]<<endl;
    }  
}
int plusThree_prod(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        int index = reminder_methord(a[i]);
        //int index = folding_methord(a[i]);
        //int index = midsqare_methord(a[i]);
        if(arr[index] == 0){
            arr[index] = a[i];
        }else{
            while(arr[index] != 0){
                index = (index+3)%N;
            }
            arr[index] = a[i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout<<arr[i]<<endl;
    }  
}

int quadratic_prod(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        int index = reminder_methord(a[i]);
        //int index = folding_methord(a[i]);
        //int index = midsqare_methord(a[i]);
        if(arr[index] == 0){
            arr[index] = a[i];
        }else{
            int j = index;
            int k=1;
            while(arr[index] != 0){
                index = (j+(k*k))%N;
                k++;
            }
            arr[index] = a[i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout<<arr[i]<<endl;
    }  
}

int chaining_prod(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        int index = reminder_methord(a[i]);
        //int index = folding_methord(a[i]);
        //int index = midsqare_methord(a[i]);
        insert(head[index],a[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if(head[i] != NULL){
            display(head[i]);
        }
    }  
}






int main(){
    int n=9,a[n]={54, 26, 93, 17, 77, 31, 44, 55, 20};
    // Answer to the question No.4
    // chaining_prod(a,n);
    // quadratic_prod(a,n);
    // plusThree_prod(a,n);
    linear_prod(a,n);
     
     
     


    
}