#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;


struct patient
{
    long long ID;
	string f_name;
	string l_name;
	int age;
	char blood_group[5];
	char gender;
    patient*next;
};// patient details

class linked
{
	patient *head,*last;
	public:
	linked() 
	{
		head=NULL;
		last=NULL;
	}
    patient input();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void patients_list();
    int search(int);
    char departmentname[50];
};// all the funtions in the code of each type

int linked :: search(int item)
{
	if(head==NULL)
		return false;
	else
	{
			int flag=0;
			patient*p=new patient();
			p=head;
		
		while( p->next!=NULL && p->ID!=item )
		{
			p=p->next;
		}
		if(p->ID==item)
		{
			flag=1;
			return true;
		}
		if(flag==0)
			return false;
	}
}

int readnumber()
{
   char b[20];
   cin.getline(b, sizeof(b));
   return atoi(b);
}

patient linked :: input()  	//Taking input of patient details in differnt type
{
    int flag=0;
   patient *p=new patient();
   cout << "\n   Please enter data for patient\n";
   cout<<"\n   First name     : ";
   getline(cin,p->f_name);
   cout << "   Last name      : ";
   getline(cin,p->l_name);
   again :
   cout << "   blood_group Group    : ";
   cin>>p->blood_group;
   if((strcmp(p->blood_group,"A+")==0)||(strcmp(p->blood_group,"a+")==0)||(strcmp(p->blood_group,"A-")==0)||(strcmp(p->blood_group,"a-")==0)||
      (strcmp(p->blood_group,"B+")==0)||(strcmp(p->blood_group,"b+")==0)||(strcmp(p->blood_group,"B-")==0)||(strcmp(p->blood_group,"b-")==0)||
      (strcmp(p->blood_group,"O+")==0)||(strcmp(p->blood_group,"o+")==0)||(strcmp(p->blood_group,"O-")==0)||(strcmp(p->blood_group,"o-")==0)||
      (strcmp(p->blood_group,"AB+")==0)||(strcmp(p->blood_group,"ab+")==0)||(strcmp(p->blood_group,"AB-")==0)||(strcmp(p->blood_group,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\n   Invalid blood_group Group Try Again..\n\n";
        goto again;

    }
   cout<<"   Gender(m/f)    : ";
   cin>>p->gender;
   cout<<"   Age            : ";
   cin>>p->age;
   cout<<"   Mobile number  : ";
   cin>>p->ID;


	if(search(p->ID))
	{
		p->ID=0;
		cout << "\n   Data not valid. Operation cancelled.";
	}
	return *p;
}

void output(patient *p) // Displaying the patients given input

{
	cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<"\n   Patient data:\n";
	cout<<"\n   First Name         : "<<p->f_name;
	cout<<"\n   Last Name          : "<<p->l_name;
	cout<<"\n   Gender             : "<<p->gender;
	cout<<"\n   Age                : "<<p->age;
	cout<<"\n   blood_group Group  : "<<p->blood_group;
	cout<<"\n   Mobile Number      : "<<p->ID;
	cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}
void linked :: insertatbeg() // critical patient entry
{
	patient*p=new patient();
	*p=input();
	if(p->ID==0)
	return;
	
	if(head==NULL)
	
	{
		head=p;
		last=p;
		p->next=NULL;
	}
	else
	{
		p->next=head;
		head=p;
	}
	system("cls");
	cout << "\n\tPatient added:";
	output(p);
}
void linked:: insertatend() //inserting normal patient data
{
	patient*p=new patient();
	*p=input();
	if(p->ID==0)
	return;
	
	if(head==NULL)
	{
		head=p;
		last=p;
		p->next=NULL;
	}
	else
	{
		p->next=NULL;
		last->next=p;
		last=p;
	}
	system("cls");
	cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
	cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
	cout <<"\n  ----------PATIENT ADDED-----------";
	output(p);
}
void linked :: getpatientout() 
{
	system("cls");
	if(head==NULL)
	{
		cout<<"\n  No Patient to operate";
	}
	else
	{
		patient*p=new patient();
		p=head;
		head=head->next;
		cout << "\n  Patient to operate:";
		output(p);
	}
}

void linked :: patients_list()	// displaying all patients data
{
	if(head==NULL)
	{
		cout<<"\n  No patient";
	}
	system("cls");
	cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
	cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
	patient*p=new patient;
	p=head;
	while(p!=NULL)
	{
		cout<<"\n   Patient data:\n";
		cout<<"\n   First Name       : "<<p->f_name;
		cout<<"\n   Last Name        : "<<p->l_name;
		cout<<"\n   Gender           : "<<p->gender;
		cout<<"\n   Age              : "<<p->age;
		cout<<"\n   blood_group Group      : "<<p->blood_group;
		cout<<"\n   Mobile Number    : "<<p->ID;
		cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
		p=p->next;
	}
	cout<<"\n";
}


void departmentmenu (linked * q)
{
    int choice = 0, success;
    patient p;
    while (choice != 5)
	{
    system("cls");
    cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<"\n\n   "<<q->departmentname;
	cout<<"\n   [1] Add normal patient\n";
	cout<<"   [2] Add critically ill patient\n";
	cout<<"   [3] Take patient to Doctor\n";
	cout<<"   [4] Display list\n";
	cout<<"   [5] Change department or exit\n";
	cout<<"\n   Please enter your choice : ";
	choice=readnumber();
	cout<<"  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";

    switch (choice)
	{
	  case 1:	q->insertatend();
				cout << "\n   Press any key";
	    		getch();
	 			break;

      case 2:	q->insertatbeg();
	    		cout << "\n   Press any key";
	    		getch();
				break;

      case 3:	q->getpatientout();
	 			cout<<"\n   Press any key";
     			getch();
	      		break;

      case 4:	system("cls");
	 			q->patients_list();
	 			cout<<"\n   Press any key";
	 			getch();
				break;
	 }
    }
}


int main ()
{
    int i, choice = 0;
	linked departments[4];

	while(choice!=5)
	{
		strcpy(departments[0].departmentname,"GENERAL CLINIC\n");
		strcpy(departments[1].departmentname,"HEART CLINIC\n");
		strcpy(departments[2].departmentname,"LUNG CLINIC\n");
		strcpy(departments[3].departmentname,"PLASTIC SURGERY\n");
		system("cls");
		cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
		cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
		cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
		cout<<"   Main Menu\n\n";
		for (i = 0; i < 4; i++)
		{
			cout<<"   "<<(i+1)<<": "<<departments[i].departmentname;
		}
		cout<<"   5: Exit";
		cout<<"\n\n   Please enter your choice : ";
		choice=readnumber();
		if(choice>=1 && choice<=4)
		{
			departmentmenu(&departments[choice-1]);
		}

	}
	if(choice==5)
	cout<<"\n\t\tThank you! \n";
	exit(0);
}


