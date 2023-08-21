#include <bits/stdc++.h>
using namespace std;

struct node {
	char data;
	node* next;
};
void insert(node* &head, char s) {
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
    if(head->next == NULL){
        head = NULL;
        return;
    }else if(head == NULL){
        cout<<"Stack is empty"<<endl;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}
char top(node* &head){
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp->data;
}
bool isOparetor(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return true;
    }
    return false;
}
bool inNumber(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')'){
        
        return false;
    }
    return true;
    
}
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string infixtoPostfix(string &infix){
    
    node* stack = NULL;
    string postfix = "";
    cout<<infix<<endl;
    for(char c:infix){
        
        if(inNumber(c)){
            
            postfix += c;
            // cout<<postfix<<endl;
            // display(stack);
           
        }else if(c == '('){
             
            insert(stack, c);
            // cout<<postfix<<endl;
            // display(stack);
        }else if(c == ')'){
            
            while(stack != NULL && top(stack) != '('){
                postfix += top(stack);
                remove(stack);   
            }
            remove(stack);
    
        }else if(isOparetor(c)){
            
            while(stack != NULL && getPrecedence(c) <= getPrecedence(top(stack))){
                postfix += top(stack);
                
                remove(stack);
            }
            insert(stack, c);
            // cout<<postfix<<endl;
            // display(stack);
        }
        
        
    }
    
    
    while(stack != NULL){
     
        postfix += top(stack);
        remove(stack);
        
        
    }
    return postfix;
    
   
}

int postfixtoSum(string &str){
    stack<int> s;
    for(char c:str){
        // cout<<s.top()<<endl;
        if(isOparetor(c)){
            int b =s.top();
            s.pop();
            int a =s.top();
            s.pop();
            int k;
            if(c=='+'){
                k=a+b;
            }else if(c=='-'){
                k=a-b;
            }else if(c=='/'){
                k=a/b;
            }else if(c=='^'){
                k = (int) pow(a,b);
            }else{
                k=a*b;
            }
            s.push(k);

        }else{
            if(c=='a'){
                s.push(3);
            }else if(c=='b'){
                s.push(2);
            }else if(c=='c'){
                s.push(1);
            }else{
                s.push(c-'0');
            }
            
        }
    }
    return s.top();
}





int main(){
    string infix = "(5+3)*2-(7/2)+(4^3)";
    // Answer to the  question No.4
    string postfix = infixtoPostfix(infix);
    // Answer to the  question No.3 and 5
    int sum = postfixtoSum(postfix);
    //string postfix = infixtoPostfix("a+b*c");
    cout<<postfix<<endl;
    cout<<sum<<endl;
   

    return 0;
}