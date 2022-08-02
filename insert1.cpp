#include <iostream>
#include <iomanip>
using namespace std;

// Student Class
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
// Sivrong
// Function to insert the record

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



void Show_Record()
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

// Driver code
int main()
{
  head = NULL;
  string firstName, lastName, email, phone, courseCode;
  int grade;
  int Choice;

  // Menu-driven program
  while (true)
  {
    cout << "\nWelcome to student database menu!\n\tPress 1 to "
        "insert a new Record\n\tPress 2 to delete a "
        " record\n\tPress 3 to Search a database(by last name) "
        "Record\n\tPress 4 to print a range in the database"
        "\n\tPress 5 to find the class average for a course\n\tPress 9 to quit\n";
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
    else if (Choice == 4)
    {
        Show_Record();
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
