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
void dfs(node* head[], int s){
    visited[s] = true;
    cout<<s<<" ";
    node* temp = head[s];
    while(temp != NULL){
        if(visited[temp->data] == false){
            dfs(head, temp->data);
        }
        temp = temp->next;
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
        dfs(head, 1);
    return 0;
}