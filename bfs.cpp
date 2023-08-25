#include <bits/stdc++.h>
using namespace std;
bool visited[100] = {false};
struct node {
	int data;
	node* next;
};
node* head[100] = {NULL};
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
int front(node* &head){
    if(head == NULL){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    node* temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    return temp->data;
}
void remove(node* &head){
    node* temp = head;
    if(head->next == NULL){
        head = NULL;
        return;
    }else if(head == NULL){
        cout<<"Stack is empty"<<endl;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}

void bfs(node* head[], int s){
    
    node* temp=NULL;
    insert(temp, s);
    visited[s] = true;
    cout<<s<<" ";
    while(temp){
        int u = front(temp);
        remove(temp);
        node* tamp = head[u];
        while(tamp != NULL){
            if(visited[tamp->data] == false){
                insert(temp,tamp->data);
                cout<<tamp->data<<" ";
                visited[tamp->data] = true;
            }
            tamp = tamp->next;
        }
    }

}

int main(){
    string s;
    while(cin>>s){
        if(s=="end"){
            break;
        }
        if(s=="n"){
            int a,b;
            cin>>a>>b;
            insert(head[a],b);


        }
    }
    for (int i = 0; i < 10; i++)
    {
        
        if(head[i]){
            cout<<i<<" -> ";
            display(head[i]);
        }
        
    }
    cout<<endl;
        bfs(head, 1);
    return 0;
}