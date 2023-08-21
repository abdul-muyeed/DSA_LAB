#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;
};
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
void remove(node* &head){
    node* temp = head;
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
        if(s=="push"){
            // Answer to the  question No.1
            int a;
            cin>>a;
            insert(head, a);
        }else  if(s=="pop"){
            // Answer to the  question No.2
            remove(head);
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