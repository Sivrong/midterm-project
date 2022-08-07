
#include <iostream>
#include <iomanip>
using namespace std;

//You can put delete function under insert function and call the function in choice 2
//You can put print range under the show record function here and call the function in choice 4
//You can put calculate average on top of the show all function here and acall the function in choice 5

// Student Class
// Lay Sivrong
struct Student
{
public:
  string firstName;
  string lastName;
  string email;
  string phone;
  string courseCode;
  int grade;
  int position;
  Student* next;
};

// Stores the head of the Linked List
Student* head = new Student();

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
    //return head;
  }
  else
  {
    t->position = head->position+1;
    t->next = NULL;

    t->next = head;
    head = t;
    //return head;
  }

  cout << "Record Inserted "
     << "Successfully\n";
}

//Long Chan Seka and Chhin Somalin

void deleteRecord(Student** head, int position)
{
    Student* temp;
    Student* forw;
    Student* curr = *head;
    Student* prev = *head;
    // In Linked List is empty Just return it
    if (*head==NULL)
    cout<<"No records to delete";
  
//        if (curr == NULL)
//        return;
    //    unlink the Student from linklist
        else if(position == 1) 
        {
            *head = curr->next;
            free(curr);
            curr = NULL;
            cout<<"Record is deleted";
            
        }
        else
        {
          while(position!=1)
          {
            prev= curr;
            curr=curr->next;
            position--;
          }
          prev->next=curr->next;
          free(curr);
          curr = NULL; 
        }
//        if(position > curr->position)
  //      {
    //      cout<<"You entered incorrect position . Linked list is out of bound!!!";
      //  }
}

//Chea Jonathan
void Show_Record(struct Student* head)
{
  
  if (head == NULL)
  {
    cout << "No Record Available\n";
  }
  Student* ptr;
  ptr = head;
    // Until p is not NULL
    while (ptr != NULL)
    {
        cout << "Course Code :\t"<<ptr->courseCode << "\n";
        cout <<"First Name :\t"<<ptr->firstName << "\n";
        cout <<"Last Name :\t"<< ptr->lastName << "\n";
        cout << "Phone :\t"<<ptr->email << "\n";
        cout <<"Phone :\t"<<ptr->phone << "\n";
        cout <<"Grade :\t"<<ptr->grade << "\n";
        cout <<"Position :\t"<<ptr->position<< endl;
        ptr = ptr->next;
    }
}


//Suy Visal & Meach SopheaVicheka
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
  int Student;
  int position;
// Menu-driven program
  while (true)
  {
    cout << "\nWelcome to student position base menu!\n\t"
        "Press 1 to insert a new Record\n\tPress 2 to delete a "
        "Press 2 to delete a record\n\t"
        "Press 3 to Search a position base(by last name) Record\n\t"
        "Press 4 to print a range in the position base\n\t"
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
     insertRecord(firstName, lastName, email, phone, courseCode,grade);
    }
    else if (Choice == 2)
    {
    //Student* head ;
   // head = push(head, position);
 //   head = push(head, 2);
 //   head = push(head, 3);
 //   head = push(head, 2);
 //   head = push(head, 8);
  //  head = push(head, 1);
 //   head = push(head, 2);
 //   head = push(head, 2);
  
    // Key to delete
    cout << "Enter the position to delete: ";
    cin >> position;
    //cin >> key;
    //int key = 2;
    //cout << "Created Linked List:\n ";
    //printList(head);
    // Function call
     deleteRecord(&head, position);
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
        Show_Record(head);
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
}
