#include<iostream>
#include<string>
using namespace std;

void mainMenu();
void register_New_Car();
void display_Detail_Registered_Cars();
void display_Type2_Cars();
void addNewRide();
void display_Ride_With_Details();
void total_earning_ofASpecific_Car();
void display_Earning_of_All_Cars();

struct Ride{
    int kms;
    double charges;
    string riderName;
    Ride *nextRideDetail = NULL;
};
struct Car{
    string driverName;
    string carName;
    string regNumber;
    int carType;
    Ride *rideNext = NULL;
    Car *next = NULL;
};

Car *first = NULL;
Car *last = NULL;


int main(){
    mainMenu();
};
void mainMenu(){
    cout<<"\n You can Peform These Tasks \n";
    cout<<"1 - Register New Car \n";
    cout<<"2 - Display Detail of New Car \n";
    cout<<"3 - Display type-2 cars \n";
    cout<<"4 - Add New Ride \n";
    cout<<"5 - Display Ride With Detail \n";
    cout<<"6 - Total Earning of Specific Car \n";
    cout<<"7 - Display Earning of all cars \n";
    cout<<"\n Enter Your Choice: ";
    int option;
    cin>>option;

    switch(option){
        case 1:
            register_New_Car();
            break;
        case 2:
            display_Detail_Registered_Cars();
            break;
        case 3:
            display_Type2_Cars();
            break;
        case 4:
            addNewRide();
            break;
        case 5:
            display_Ride_With_Details();
            break;
        case 6:
            total_earning_ofASpecific_Car();
            break;
        case 7:
            display_Earning_of_All_Cars();
            break;
        default:
            cout<<"<<< Invalid Option >>>";
            cout<<"PLEASE ENTER AGAIN";
            mainMenu();
    }
}
void register_New_Car()
{
    Car *current = new Car;

    cout<<"Enter Driver Name: ";
    cin>>current->driverName;

    cout<<"Enter Car Name: ";
    cin>>current->carName;

    cout<<"Enter Registration Number: ";
    cin>>current->regNumber;

    cout<<"Enter Car Type (1/2): ";
    cin>>current->carType;


    if (first == NULL){
        first = last = current;
    }
    else{
        last->next = current;
        last = current;
    }
    mainMenu();
}
void display_Detail_Registered_Cars(){

    cout<<"This Is the function of Display Detail Registered Cars \n";

    Car *p = first;
    if (first==NULL){
        cout<<"Linked List Is Empty";
    }else{
        int count = 1;
        while(p!=NULL)
        {
			cout<<endl;
			cout<<"Car: "<<count<<endl;
            cout<<"Driver "<<"Name: "<<p->driverName<<endl;
            cout<<"Car "<<"Name: "<<p->carName<<endl;
            cout<<"Registration "<<"Number: "<<p->regNumber<<endl;
            cout<<"Car "<<"Type: "<<p->carType<<endl;
			cout<<endl;
			count++;
            p = p->next;
        }
    }
    mainMenu();
}
void display_Type2_Cars(){
	cout<<"This Is the function of Display Type 2 Cars \n";

    Car *p = first;
    if (first==NULL){
        cout<<"Linked List Is Empty";
    }else{
        int count = 1;
        while(p!=NULL)
        {
			if (p->carType==2){
				cout<<endl;
				cout<<"Car: "<<count<<endl;
				cout<<"Driver "<<"Name: "<<p->driverName<<endl;
				cout<<"Car "<<"Name: "<<p->carName<<endl;
				cout<<"Registration "<<"Number: "<<p->regNumber<<endl;
				cout<<"Car "<<"Type: "<<p->carType<<endl;
				cout<<endl;
				count++;
				p = p->next;
			}
			else{
				p = p->next;
			}
        }
    }
    mainMenu();
}
void addNewRide()
{
	//display_Detail_Registered_Cars();
	
	if(first != NULL){	
		int count;
		bool check;
		Car *p = first;
		int i;
		do{	
			check = false;
			cout<<endl<<"Enter Car Number to Add a New Ride: ";
			cin>>count;
			
			for(i = 1; i<count;i++){
				p = p->next;
				if(p==NULL){
					cout<<endl<<"\n\n<< Car Not Found! >>\n\n";
					check = true;
					i = count;
				}
			}
		}while(check);
		
		cout<<"\t\t <<<<<<<< YOUR CAR SELECTION IS >>>>>>> \n";
		cout<<"Car Is: "<<p->carName<<endl;
		cout<<"Driver Name: "<<p->driverName<<endl;
		
		Ride *current = new Ride;
		
		cout<<"Enter Rider Name: ";
		cin>>current->riderName;
		
		cout<<"Enter Distance (km): ";
		cin>>current->kms;
		
		cout<<"Enter Charges: ";
		cin>>current->charges;
		
		if(p->rideNext != NULL){
			current->nextRideDetail = p->rideNext;
			p->rideNext = current;
		}
			p->rideNext = current;
	}
	else{
		cout<<"\n\n <<<No Car Record Found>>>> \n\n";
	}
    mainMenu();
}
void display_Ride_With_Details(){
	
	if(first != NULL){	
		int count;
		bool check;
		Car *p = first;
		int i;
		do{	
			check = false;
			cout<<endl<<"Enter Car Number to Display Ride Detail: ";
			cin>>count;
			
			for(i = 1; i<count;i++){
				p = p->next;
				if(p==NULL){
					cout<<endl<<"\n\n<< Car Not Found! >>\n\n";
					check = true;
					i = count;
				}
			}
		}while(check);
		
		cout<<"\t\t <<<<<<<< YOUR CAR SELECTION IS >>>>>>> \n";
		cout<<"\t\t\t\tCar Is: "<<p->carName<<endl;
		cout<<"\t\t\t\tDriver Name: "<<p->driverName<<endl;
		
		count = 1;
		Ride *k = p->rideNext;
		while(k != NULL){
			cout<<endl;
			cout<<"Car Number: "<<count<<endl;
			cout<<"Rider Name: "<<k->riderName<<endl;
			cout<<"Distance: "<<k->kms<<endl;
			cout<<"Charges: "<<k->charges<<endl;
			k = k->nextRideDetail;
			count++;
		}
		if(count == 1){
			cout<<endl<<"\n\n <<< No Ride Record Found >>> \n\n";
		}
	}
	else{
		cout<<"\n\n <<< No Car Record Found >>> \n\n";
	}
    mainMenu();
}
void total_earning_ofASpecific_Car(){
	
	if(first != NULL){	
		int count;
		bool check;
		Car *p = first;
		int i;
		do{	
			check = false;
			cout<<endl<<"Enter Car Number to Display It's Earning: ";
			cin>>count;
			
			for(i = 1; i<count;i++){
				p = p->next;
				if(p==NULL){
					cout<<endl<<"\n\n<< Car Not Found! >>\n\n";
					check = true;
					i = count;
				}
			}
		}while(check);
		
		int sum = 0;
		Ride *k = p->rideNext;
		while(k!=NULL){
			sum += k->charges;
			k = k->nextRideDetail;
		}
		cout<<"Car Name Is: "<<p->carName<<endl;
		cout<<"Total Earning Is: "<<sum<<" Rupees"<<endl;
	}
	else{
		cout<<"\n\n <<< No Car Record Found >>> \n\n";
	}
    mainMenu();
}
void display_Earning_of_All_Cars(){
	
	int sum = 0;
	if(first != NULL)
	{	
		Car *p = first;
		while(p!=NULL){
			Ride *k = p->rideNext;
			while(k!=NULL){
				sum += k->charges;
				k = k->nextRideDetail;
			}
			p = p->next;
		}
		cout<<"Total Earning Is: "<<sum<<" Rupees"<<endl;
	}
	else{
		cout<<"\n\n <<< No Car Record Found >>> \n\n";
	}
    mainMenu();
}