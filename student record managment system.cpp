
/*
section 1
Abduselam Tesfaye ----> UGR/25696/14
Nahom habtamu --------> UGR/25347/14
Hayat mussa ----------> UGR/30639/15
Arsema Wondwossen-----> UGR/30186/15
Abenezer Alemayehu----> UGR/30071/15
*/
#include <bits/stdc++.h>
using namespace std;

// Node Class
struct Node {

	int Id;
	string First_name;
    string Last_name;
	Node* next;
};

// Stores the head of the Linked List
Node* head = NULL;
int node_num=0;
// Function to check that if the entered Id exists
// Record Already Exist or Not
bool check(int id)
{
	// Base Case
	if (head == NULL)
		return false;

	Node* temp = new Node;
	temp = head;

	// Traverse the Linked List
	while (temp != NULL) {
		if (temp->Id == id)
			return true;
		temp = temp->next;
	}

	return false;
}

// Function to insert the record
void Insert_Record(int Id, string First_name,string Last_name)
{
	// if Record Already Exist
	if (check(Id)) {
		cout << "Student with this "
			<< "record Already Exists\n";
		return;
	}

	// Create new Node to Insert Record
	Node* temp = new Node;
	temp->Id = Id;
	temp->First_name = First_name;
	temp->Last_name = Last_name;
	temp->next = NULL;

	// Insert at Begin
	if (head == NULL)
	 {
		head = temp;
	}

	// Insert at middle or End
	else {
		Node* temp1 = head;
		while (temp1->next != NULL)
            temp1=temp1->next;

		temp1->next = temp;
	}
    node_num++;

	cout<< "Record Inserted "<< "Successfully\n";
}

// Function to search record for any
// students Record with roll number
void Search_Record(int Id)
{
	// if head is NULL
	if (!head) {
		cout << "No such Record "
			<< "Avialable\n";
		return;
	}

	// Otherwise
	else {
		Node* p = head;
		while (p) {
			if (p->Id == Id) {
				cout << "Id Number\t"
					<< p->Id << endl;
				cout << "First name\t\t"
					<< p->First_name<< endl;
				return;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "No such Record "
				<< "Avialable\n";
	}
}

// Function to delete record students
// record with given roll number
// if it exist
void Delete_Record(int i)           //function to delete a node
{
    if (head==NULL)
        cout<<"empty list";
    else
    {
        Node *temp=head,*prev=NULL;     //fist search for a node then if that node is found delete it..and make the previous node point to the next node.
        if(temp->Id==i)
        {
            head=temp->next;
            delete temp;
            return;
        }else{

        while(temp!=NULL && temp->Id!=i)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
                cout<<"ID NOT FOUND.";
            return;
        }
        prev->next=temp->next;
        delete temp;
    }
    node_num--;
    }

}

// Function to display the Student's
// Record
void Show_Record()
{
	Node* p = head;
	if (p == NULL) {
		cout << "No Record "
			<< "Available\n";
	}
	else {
		cout << "ID\tName\tLast Name\n";

		// Until p is not NULL
		while (p != NULL) {
			cout << p->Id << " \t"
				<< p->First_name << " \t"<< p->Last_name <<  "\t"<< endl;
			p = p->next;
		}
	}
}


void update(int i)  //function to update a node using student id
{
    string fname,lname;
    if (head==NULL)
        cout<<"List is Empty!";                     //first search if the id exists in the list if t exists display the current data and prompt user to enter new data.
    else
    {
        Node *temp=head,*prev=NULL;
        if(temp->Id==i)
        {
            cout<<endl;
            cout<<"Current data: \n";
            cout<<temp->Id<<" ";
            cout<<temp->First_name<<" ";
            cout<<temp->Last_name<<" ";
            cout<<"\nEnter student first name: ";
            cin>>fname;
            cout<<"Enter student last name: ";
            cin>>lname;
            temp->First_name=fname;
            temp->Last_name=lname;
            return;
        }else{

        while(temp!=NULL && temp->Id!=i)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"ID Not found";
            return;
        }
        cout<<endl;
        cout<<"Current data: \n";
        cout<<temp->Id<<" ";
        cout<<temp->First_name<<" ";
        cout<<temp->Last_name<<" ";
        cout<<"\nEnter student first name: ";
        cin>>fname;
        cout<<"Enter student last name: ";
        cin>>lname;
        temp->First_name=fname;
        temp->Last_name=lname;
    }
    }

}






void sor()
{
    Node *sorted_head=NULL;
    string ar[node_num];
    int n=0;
    if (head==NULL)
        cout<<"empty list";
    else
    {
        Node* temp=head;
        while(temp->next!=NULL)
        {
            ar[n]=temp->First_name;
            n++;
            temp=temp->next;
        }
        ar[n]=temp->First_name;
    }
    sort(ar,ar+n+1);
    for (int i=0;i<=n;i++)
    {

		Node *tempN=head;
		if(tempN->First_name==ar[i])
		{

			//insert to new_node;

			Node *newnode=new Node;
    newnode->Id=tempN->Id;
    newnode->First_name=tempN->First_name;
    newnode->Last_name=tempN->Last_name;
    newnode->next=NULL;

    if (sorted_head==NULL)
        sorted_head=newnode;
    else
    {
        Node *temps=sorted_head;
        while(temps->next!= NULL)
        {
            temps=temps->next;
        }
        temps->next=newnode;
    }
		}
		else{

        while(tempN!=NULL && tempN->First_name!=ar[i])
        {
            tempN=tempN->next;
        }
		//insert to new_node;

    Node *newnode=new Node;
    newnode->Id=tempN->Id;
    newnode->First_name=tempN->First_name;
    newnode->Last_name=tempN->Last_name;
    newnode->next=NULL;

    if (sorted_head==NULL)
        sorted_head=newnode;
    else
    {
        Node *temps=sorted_head;
        while(temps->next!= NULL)
        {
            temps=temps->next;
        }
        temps->next=newnode;
    }

    }
}

head=sorted_head;
}

// Driver code
int main()
{
	head = NULL;
	string Name, Lname;
	int Sid, Marks;

	// Menu-driven program
	while (true) {
		cout << "\nWelcome to Student Record Management System\nPress:\n1 to create a new Record\n2 to delete a student record\n"
                "3 to Search a Student\n4 to update a recored\n5 to view all students record\n6 to sort the student record\n7 About Developer\n8 exit";
		cout << "\nEnter your Choice\n";
		int Choice;

		// Enter Choice
		cin >> Choice;
		if (Choice == 1) {
			cout << "Enter Name of Student\n";
			cin >> Name;
			cout << "Enter last Name of Student\n";
			cin >> Lname;
			cout << "Enter Id Number of Student\n";
			cin >> Sid;
			Insert_Record(Sid, Name, Lname);
		}
		else if (Choice == 2) {
			cout << "Enter Id Number of Student whose "
					"record is to be deleted\n";
			cin >> Sid;
			Delete_Record(Sid);
		}
		else if (Choice == 3) {
			cout << "Enter Id Number of Student whose "
					"record you want to Search\n";
			cin >> Sid;
			Search_Record(Sid);
		}
		else if (Choice == 4) {
			cout << "Enter Id Number of Student whose "
					"record you want to Update\n";
			cin >> Sid;
			update(Sid);
		}
		else if (Choice == 5) {
			Show_Record();
		}
		else if (Choice==6){
            sor();
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->First_name << " ";
                temp = temp->next;
    }
		}
		else if (Choice == 8) {
			exit(0);
		}
		else if (Choice == 7){
            cout<<"Abduselam Tesfaye ----> UGR/25696/14 "<<endl;
            cout<<"Nahom habtamu --------> UGR/25347/14 "<<endl;
            cout<<"Hayat mussa ----------> UGR/30639/15 "<<endl;
            cout<<"Arsema Wondwossen-----> UGR/30186/15 "<<endl;
            cout<<"Abenezer Alemayehu----> UGR/30071/15 "<<endl;

		}
		else {
			cout << "Invalid Choice "
				<< "Try Again\n";
                break;
		}
	}
	return 0;
}
