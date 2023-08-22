#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;
};

void insertF(node* &head, int s) {
    node* temp = new node;
    temp->data = s;
	temp->next = head;
	head = temp;
	
	
	
	
}
void insertB(node* &head, int s) {
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
void removeF(node* &head){
    if(head == NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    head = head->next;
}
void removeB(node* &head){
    node* temp = head;
    if(head->next == NULL){
        head = NULL;
        return;
    }else if(head == NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}
int main(){
    node* head = NULL;
    string s;
    while(1){
        cin>>s;
        if(s=="bpush"){
            // Answer to the  question No.9
            int a;
            cin>>a;
            insertB(head, a);
        }else if(s=="fpush"){
            // Answer to the  question No.9
            int a;
            cin>>a;
            insertF(head, a);
        }else  if(s=="bpop"){
            // Answer to the  question No.10
            removeB(head);
        }else  if(s=="fpop"){
            // Answer to the  question No.10
            removeF(head);
        }else if(s=="show"){
            display(head);
        }else if(s=="exit"){
            break;
        }else{
            cout<<"Valid Input are push,pop,show,exit"<<endl;
        }
    }
   

    return 0;
}