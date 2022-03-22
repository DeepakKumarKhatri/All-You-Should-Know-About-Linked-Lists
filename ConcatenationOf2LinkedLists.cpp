#include<iostream>
using namespace std;
struct Student{
	int id;
	int marks;
	Student *next = NULL;
};
Student *first1 = NULL;
Student *last1 = NULL;
Student *first2 = NULL;
Student *last2 = NULL;

void displayLL1();
void insert_endLL1();
void displayLL2();
void insert_endLL2();
void mainMenu();
void displayConcatenate();
void concatenate2LL();

int main(){
    mainMenu();
}
void mainMenu(){
    cout<<"\nWhich task you want to perform"<<endl;
    cout<<"1 - Insert At LL1 End \n";
	cout<<"2 - Insert At LL2 End \n";
	cout<<"3 - Display the LL1 \n";
	cout<<"4 - Display the LL2 \n";
	cout<<"5 - Merge Two \n";
	cout<<"6 - Display the Merge \n";
	
    cout<<"Enter Your Option: ";
    int option;
    cin>>option;

    switch(option){
		
		case 1:
			insert_endLL1();
			break;
		case 2:
			insert_endLL2();
			break;
		case 3:
			displayLL1();
			break;
		case 4:
			displayLL2();
			break;
		case 5:
			concatenate2LL();
			break;
		case 6:
			displayConcatenate();
			break;
    }
}
void insert_endLL1(){
    cout<<"This is the function of insert_end LL1 \n";
	
	Student *current = new Student;
	cout<<"Enter ID: ";
	cin>>current->id;
	
	
	if (first1==NULL){
		first1 = last1 = current;
	}
	else{
		last1->next = current;
		last1 = current;
	}
	mainMenu();
}
void insert_endLL2(){
    cout<<"This is the function of insert_end LL2 \n";
	
	Student *current = new Student;
	cout<<"Enter ID: ";
	cin>>current->id;
	
	if (first2==NULL){
		first2 = last2 = current;
	}
	else{
		last2->next = current;
		last2 = current;
	}
	mainMenu();
}
void displayLL1(){
	cout<<"This is the function of display_The_LinkedList 1 \n";
	
	Student *p = first1;
	if (first1==NULL){
		cout<<"Linked List Is Empty";
	}else{
		while(p!=NULL)
		{
			cout<<"ID: "<<p->id<<endl;
			p = p->next;
		}
	}
	mainMenu();
}
void displayLL2(){
	cout<<"This is the function of display_The_LinkedList 1 \n";
	
	Student *p = first2;
	if (first2==NULL){
		cout<<"Linked List Is Empty";
	}else{
		while(p!=NULL)
		{
			cout<<"ID: "<<p->id<<endl;
			p = p->next;
		}
	}
	mainMenu();
}
void concatenate2LL(){
	cout<<"This is the function of Concatenation of 2 Linked Lists \n";
	
	Student *p = first1;
	while(p->next!=NULL){
		p = p->next;
	}
	p->next = first2;
	mainMenu();
}
void displayConcatenate(){
	cout<<"This is the function of Displaying the concatenated 2 Linked Lists \n";
	
	Student *p = first1;
	if (first1==NULL){
		cout<<"Linked List Is Empty";
	}else{
		while(p!=NULL)
		{
			cout<<"ID: "<<p->id<<endl;
			p = p->next;
		}
	}
	mainMenu();
}