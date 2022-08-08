#include <iostream>
#include <iomanip>
using namespace std;

//You can put delete function under insert function and call the function in choice 2
//You can put print range under the show record function here and call the function in choice 4
//You can put calculate average on top of the show all function here and acall the function in choice 5

// Student Class
// Lay Sivrong
class Student
{
public:
  string firstName;
  string lastName;
  string email;
  string phone;
  string courseCode;
  int grade;
  int position;
  Student *next;
};

// Stores the head of the Linked List
Student *head = new Student();

// Check Function to check that if
// Record Already Exist or Not
bool check(string x)
{
  // Base Case
  if (head == NULL)
    return false;

  Student *t = new Student;
  t = head;

  // Traverse the Linked List
  while (t != NULL)
  {
    if (t->lastName == x)
      return true;
    t = t->next;
  }

  return false;
}

// Function to insert the record
//Thao Sotheavatey
void insertRecord(string firstName,
           string lastName,
           string email,
           string phone,
           string courseCode,
           int grade)
{
  
  // if Record Already Exist 
  
  if (check(courseCode))
  {
    cout << "Student with this "
       << "record Already Exists\n";
    return;
  }

  // Create new Student to Insert Record
  Student *t = new Student();
  t->courseCode = courseCode;
  t->firstName = firstName;
  t->lastName = lastName;
  t->email = email;
  t->phone = phone;
  t->grade = grade;
  t->next = NULL;

  // Insert at Begin
  if (head == NULL) {
    t->position = 1;
    // t->next = head;
    head = t;
      
  }
  else
  { 
    t->position = head->position+1;
    t->next = head;
    head = t;
  }

  cout << "Record Inserted "
     << "Successfully\n";
}

//Long Chan Seka and Chhin Somalin
void deleteRecord()
{
	
}

//Chea Jonathan and Eak Tech Hav
void showAllRecords()
{
  Student *p = head;
  if (p == NULL)
  {
    cout << "No Record Available\n";
  }
  else
  {
    cout << "Course Code\t\tFirst Name\t\tLast Name\t\tEmail\t\tPhone\t\tGrade\t\tPosition\n";

    // Until p is not NULL
    while (p != NULL)
    {
      cout << p->courseCode << "\t\t"
         << p->firstName << "\t\t"
         << p->lastName << "\t\t"
         << p->email << "\t\t"
         << p->phone << "\t\t"
         << p->grade << "\t\t"
         << p->position << endl;

      p = p->next;
    }
  }
}

void showRecordInRange(int start, int end){
    Student *students = head;
  if (students == NULL)
  {
    cout << "No Record Available\n";
  }
  else
  {
    cout << "Course Code\t\tFirst Name\t\tLast Name\t\tEmail\t\tPhone\t\tGrade\t\tPosition\n";


    while (students != NULL)
    {
        int pos = students->position;
        
        if(pos >= start && pos <= end){
        cout << students->courseCode << "\t\t"
         << students->firstName << "\t\t"
         << students->lastName << "\t\t"
         << students->email << "\t\t"
         << students->phone << "\t\t"
         << students->grade << "\t\t"
         << students->position << endl;
        }
      students = students->next;
    }
  }
}

// Option 4
void showRecordOption() {
    int choice;
    
    while(true){
        cout << "Press 1 to print all\nPress 2 to print range\nPress 3 to exit";
        cout << "\nEnter your choice\n";
        cin >> choice;
        
        
        if(choice == 1){
            showAllRecords();
        }else if (choice == 2){
            int start, end;
            cout << "\nEnter start position\n";
            cin >> start;
            
            cout << "\nEnter end position\n";
            cin >> end;
            
            showRecordInRange(start, end);
            
        }else if (choice == 3){
            break;
        }else {
        cout << "Invalid Choice "
         << "Try Again\n";
        }
    }
}
//Suy Visal & Meach SopheaVicheka
// pull request by Suy Visal
void searchRecord(string lastName)
{
	// if head is NULL
	if (!head) {
		cout << "No such Record "
			<< "Available\n";
		return;
	}

	// Otherwise
	else {
		Student* p = head;
		while (p) {
			if (p->lastName == lastName) {
				cout << "First Name\t\t"
					<< p->firstName << endl;
				cout << "Last Name\t"
				<< p->lastName << endl;
				cout << "Email\t"
					<< p->email << endl;
				cout << "Phone\t\t"
					<< p->phone << endl;
				cout << "Course Code\t\t"
					<< p->courseCode << endl;
				cout << "Grade\t"
					<< p->grade << endl;
			return;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "No such Record "
				<< "Available\n";
	}
}

// Driver code
//Lay Sivrong
int main()
{
  head = NULL;
  string firstName, lastName, email, phone, courseCode;
  int grade;
  int Choice;

  // Menu-driven program
  while (true)
  {
    cout << "\nWelcome to student database menu!\n\t"
        "Press 1 to insert a new Record\n\tPress 2 to delete a "
        "Press 2 to delete a record\n\t"
        "Press 3 to Search a database(by last name) Record\n\t"
        "Press 4 to print a range in the database\n\t"
        "Press 5 to find the class average for a course\n\t"
        "Press 9 to quit\n";
        
    cout << "\nEnter your Choice\n";

    // Enter Choice
    cin >> Choice;
    if (Choice == 1)
    {
      cout << "Enter First Name of Student\n";
      cin >> firstName;
      cout << "Enter Last Name of Student\n";
      cin >> lastName;
      cout << "Enter Email of Student\n";
      cin >> email;
      cout << "Enter Phone of Student\n";
      cin >> phone;
      cout << "Enter Course code of Student \n";
      cin >> courseCode;
      cout << "Enter Grade of Student\n";
      cin >> grade;
      insertRecord(firstName, lastName, email, phone, courseCode, grade);
    }
    else if (Choice == 2) 
    		{
	    cout << "Enter the position to delete: ";
	    cin >> position;
	    deleteRecord();
    		}
	  
    else if (Choice == 3)
		{
			cout << "Enter Last Name of Student whose "
					"record you want to Search\n";
			cin >> lastName;
			searchRecord(lastName);
		}
    else if (Choice == 4)
    {
        showRecordOption();
    }
    else if (Choice == 5)
    {
        
    }
	  
    else if (Choice == 9)
		{
			exit(0);
		}
		else
		{
			cout << "Invalid Choice "
				 << "Try Again\n";
		}
  }
  return 0;
}
