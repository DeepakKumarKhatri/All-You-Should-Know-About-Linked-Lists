//PROBLEM STATEMENT
//SINGLY LINKED-LIST OPERATION
//SWAP THE VALUES OF ANY 2 GIVEN NODES LIKE THE 2ND AND 6TH, 5TH AND 9TH, 7TH AND 3RD ETC. 

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next = NULL;
};
Node *first = NULL;
Node *last = NULL;


void insert_end();
void swapValues(int elementFrom, int elementTo);
void displayTheLinkedList();
void mainMenu();

int main(){
    mainMenu();
}
void mainMenu(){
    cout<<"\nWhich task you want to perform"<<endl;
    cout<<"1 - Insert At End End \n";
    cout<<"2 - Display the Linked list \n";
    cout<<"3 - Swap The Values \n";
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
            int elementFrom;
            int elementTo;
            cout<<"Enter The Element From Which To Swap: ";
            cin>>elementFrom;
            cout<<"Enter The Element To Which To Swap: ";
            cin>>elementTo;
            swapValues(elementFrom,elementTo);
            mainMenu();
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

void swapValues(int elementFrom, int elementTo)
{
    Node *p = first;
    Node* swap;
    while ((p->data != elementFrom)&&(p->data != elementTo)&&(p->next != NULL))
    {
        p = p->next;
    }
    if (p->data == elementFrom)
    {
        swap = p;
        p =first;
        while ((p->data != elementTo)&&(p->next != NULL))
        {
            p = p->next;
        }
        if (p->data == elementTo)
        {
            int idSwap = swap->data;
            swap->data = p->data;
            p->data = idSwap;
        }
        else
        {
            cout<<"\t\t<<<<<<<<<<<<<<< Element Not found >>>>>>>>>>>>>>>";
        }
    }
    else if (p->data == elementTo)
    {
        swap = p;
        p =first;
        while ((p->data != elementTo)&&(p->next != NULL))
        {
            p = p->next;
        }
        if (p->data == elementFrom)
        {
            int idSwap = swap->data;
            swap->data = p->data;
            p->data = idSwap;
        }
        else
        {
            cout<<"\t\t<<<<<<<<<<<<<<< Element Not found >>>>>>>>>>>>>>>";
        }
    }
    else
    {
        cout<<"\t\t<<<<<<<<<<<<<<< Element Not found >>>>>>>>>>>>>>>";
    }
    mainMenu();
}
