#include <iostream>
#include <iomanip>
#include <search.h>
using namespace std;

// Student Class
class Student {
public:
	string firstName;
	string lastName;
	string email ;
    string phone ;
    string courseCode ;
    int grade ;
	int position;
	Student* next;
};

// Stores the head of the Linked List
Student* head = new Student();

// Student* moveToPosition(int position) {
//   // Move to any position in the linked list.
//   // Returns a pointer to the grade at position.
//         int currentPosition = 0 ;
//         Student* currentPointer = head;
//         while ((currentPosition < position) && (currentPointer != NULL)) {
//             currentPointer = *currentPointer->next ;
//             currentPosition += 1 ;
//         }
//         return (currentPointer) ;
//     }
// Check Function to check that if
// Record Already Exist or Not
bool check(string x)
{
	// Base Case
	if (head == NULL)
		return false;

	Student* t = new Student;
	t = head;

	// Traverse the Linked List
	while (t != NULL) {
		if (t->lastName == x)
			return true;
		t = t->next;
	}

	return false;
}
// Function to insert the record
// Sivrong
// void searchRecord(string lastName) {

// }
void insertRecord(string firstName,
                    string lastName,
                    string email ,
                    string phone ,
                    string courseCode ,
                    int grade, 
                    int position)
{
	// if Record Already Exist
	if (check(lastName)) {
		cout << "Student with this "
			<< "Last Name Already Exists\n";
		return;
	}

	// Create new Student to Insert Record
	Student* t = new Student();
	
	t->firstName = firstName;
	t->lastName = lastName;
	t->email = email;
	t->phone = phone;
	t->grade = grade;
	t->courseCode = courseCode;
	t->position = position;
	t->next = NULL;
{
	// if Record Already Exist
	if (check(lastName)) {
		cout << "Student with this "
			<< "record Already Exists\n";
		return;
	}

	// Create new Student to Insert Record
	Student* t = new Student();
	t->courseCode = courseCode;
	t->firstName = firstName;
	t->lastName = lastName;
	t->email = email;
	t->phone = phone;
	t->grade = grade;
	t->position = position;
	t->next = NULL;

	// Insert at Begin
	
	if (head == NULL
		|| (head->lastName >= t->lastName)) {
		t->next = head;
		head = t;
	}

	// Insert at middle or End
	else {
		Student* c = head;
		while (c->next != NULL
			&& c->next->lastName < t->lastName) {
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}

	cout << "Record Inserted "
		<< "Successfully\n";
}


}
// Driver code
int main()
{
	head = NULL;
	string firstName, lastName, email, phone, courseCode;
	int grade, position;

	// Menu-driven program
	while (true) {
		cout << "\n\t\tWelcome to Student Record "
				"Management System\n\n\tPress\n\t1 to "
				"create a new Record\n\t2 to delete a "
				"student record\n\t3 to Search a Student "
				"Record\n\t4 to view all students "
				"record\n\t5 to Exit\n";
		cout << "\nEnter your Choice\n";
		int Choice;

		// Enter Choice
		cin >> Choice;
		if (Choice == 1) {
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
			cout << "Enter position of Student\n";
			cin >> position;
			insertRecord(firstName, lastName, email, phone, courseCode, position, grade );
		}
	}
	return 0;
}
