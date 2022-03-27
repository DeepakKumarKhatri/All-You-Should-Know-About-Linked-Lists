#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next = NULL;
};
Node *first = NULL;
Node *last = NULL;


void insert_end();
bool checkIfPalindrome();
void displayTheLinkedList();
void mainMenu();

int main(){
    mainMenu();
}
void mainMenu(){
    cout<<"\nWhich task you want to perform"<<endl;
    cout<<"1 - Insert At End End \n";
    cout<<"2 - Display the Linked list \n";
    cout<<"3 - Check If Palindrome \n";


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
            cout<<checkIfPalindrome();
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

bool checkIfPalindrome(){
    cout<<"This is the function of checkIfPalindrome \n";

    int count = 0;

    //for counting number of nodes in linked list
    Node *p = first;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    //for copying linked list values into array
    int arr[count];
    int arrToCheck[count];
    if (first==NULL){
        cout<<"The List Is Empty";
    }
    else{
        int i = 0;
        p = first;
        while(p!=NULL)
        {
            arr[i] = p->data;
            arrToCheck[i] = p->data;
            p = p->next;
            i++;
        }
        //for copying array elements into linked list
        p = first;
        i--;
        while(p!=NULL)
        {
            p->data = arr[i--];
            p = p->next;
        }
    }

    for(int i=0;i<count;i++){
        if(arr[i]!=arrToCheck[i]){
            return false;
        }
        return true;
    }
    mainMenu();
}
