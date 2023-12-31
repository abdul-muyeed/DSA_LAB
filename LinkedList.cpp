#include <bits/stdc++.h>
using namespace std;

struct node {
	string data;
	node* next;
};
void insert(node* &head, string s) {
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
void sort(node* &head){
    node* temp = head;
    while(temp->next != NULL){
        node* temp1 = temp->next;
        while(temp1 != NULL){
             int a = stoi(temp->data);
                int b = stoi(temp1->data);
            if(a > b){
                swap(temp->data, temp1->data);
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
}
void find(node* &head, string s){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == s){
            cout<<"Found"<<endl;
            return;
        }
        temp = temp->next;
    }
    cout<<"Not Found"<<endl;
}


int main() {
    // Answer to the  question No.1
	node* head = NULL;
	string s;
    cout<<"Enter the elements of the linked list: ";
	while (cin >> s, s != "end") {
		insert(head, s);
	}
    // Answer to the question No.2
    cout<<"The elements of the linked list are: ";
    display(head);
    // Answer to the question N0.3
    cout<<"Enter the element to be inserted: ";
    string str;
    cin>>str;
    insert(head, str);
    cout<<"The elements of the linked list are after insert: ";
    display(head);
    // Answer to the question No.4
    remove(head);
    cout<<"The elements of the linked list are after remove: ";
    display(head);
    // Answer to the question No.4
    sort(head);
    cout<<"The elements of the linked list are after sort: ";
    display(head);
    // Answer to the question No.6
    cout<<"Enter the element to be searched: ";
    string s1;
    cin>>s1;
    find(head, s1);

}

/* 1 2 35 3 9 42 0 10 end
     13432

*/ 