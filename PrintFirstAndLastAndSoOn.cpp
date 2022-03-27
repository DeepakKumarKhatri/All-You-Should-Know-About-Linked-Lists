//PROBLEM STATEMENT
//SINGLY LINKED-LIST OPERATION
//PRINT LINKED LIST IN SUCH ORDER THAT: THE OUTPUT WOULD YIELD FIRST AND LAST NODE, SECOND AND SECOND LAST, THIRD AND THIRD LAST AND SO ON... 

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next = NULL;
};
Node *first = NULL;
Node *last = NULL;

void insert_end();
void displayReduceAndReduce();
void displayTheLinkedList();
void mainMenu();

int main(){
    mainMenu();
}
void mainMenu(){
    cout<<"\nWhich task you want to perform"<<endl;
    cout<<"1 - Insert At End End \n";
    cout<<"2 - Display the Linked list \n";
    cout<<"3 - Display the Reduce And Reduce \n";
    cout<<"Enter Your Option: ";
    int option;
    cin>>option;

    switch(option){

        case 1:
            insert_end();
            break;
        case 2:
            displayTheLinkedList();
            break;
        case 3:
            displayReduceAndReduce();
            break;
    }
}

void insert_end(){
    cout<<"This is the function of insert_end \n";

    Node *current = new Node;
    cout<<"Enter ID: ";
    cin>>current->data;

    if (first==NULL){
        first = last = current;
    }
    else{
        last->next = current;
        last = current;
    }
    mainMenu();
}

void displayTheLinkedList(){
    cout<<"This is the function of display_The_LinkedList \n";

    Node *p = first;
    if (first==NULL){
        cout<<"Linked List Is Empty";
    }else{
        while(p!=NULL)
        {
            cout<<"ID: "<<p->data<<endl;
            p = p->next;
        }
    }
    mainMenu();
}

void displayReduceAndReduce(){
    cout<<"This is the function of displayReduceAndReduce \n";

    Node* p = first;
    Node* q = first;
    Node* k = NULL;

    while(p->next!=NULL)
    {
        while(q->next!=k)
        {
            q = q->next;
        }
        if(p!=q){
            cout << p->data << " " << q->data << " ";
        }
        else{
            cout<<q->data;
        }
        p = p->next;
        k = q;
        q = p;
    }
    mainMenu();
}
