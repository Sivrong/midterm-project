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

  // Insert at Begin | Insert the first node
  if (head == NULL)
  {
    t->position = 1;
    // t->next = head;
    head = t;
  }
  else
  {
    //Insert at the end
    Student* curr;
    curr = head;
    Student *t = new Student();
    t->courseCode = courseCode;
    t->firstName = firstName;
    t->lastName = lastName;
    t->email = email;
    t->phone = phone;
    t->grade = grade;
    t->position = head->position+1;

    while(curr->next != NULL)
    {
     t->position++;
     cout<<"Hey hey"; //testing to check if the code met condition in while block
     t->next = NULL;
     curr = curr->next;
    }
    curr->next = t;
  }

  cout << "Record Inserted "
     << "Successfully\n";
}

//Long Chan Seka and Chhin Somalin

void deleteRecord(Student** head, int position)
{
    Student* temp;
    Student* forw;
    Student* curr = *head; //current pointer assign to head
    Student* prev = *head; //previous pointer assign to head
    int count = 0; //count no of nodes in LL
    // In Linked List is empty Just return it
    if (*head==NULL)
    cout<<"No records to delete";
  
// if position is 1 or first node (head)
        else if(position == 1)
        {
            *head = curr->next;
            free(curr);
            curr = NULL;
            cout<<"Record is deleted";
            return;
        }
        prev =*head;
            while (prev != NULL)
          {
              count++;
                prev = prev->next;
          }
          if (count < 1 || position > count)
          {
            cout << "Invalid position";
              return;
          }
          else
        {
          prev = *head;
           //delete node position which is not equal to 1
          while(position!=1) //position is not 1
          {
            
            prev= curr; //prev pointer point to current node
            curr=curr->next; // current pointer point to next node of current
            position--; //decrement of position
            
            }
            prev->next=curr->next; // to update the previous node to the next node of the delete node
            free(curr); // free the delete node
            curr = NULL; //set delete node to null
            cout<<"Record "<<count<<"is deleted\n";
            return;
          }
          
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
        cout <<"Position :\t"<<ptr->position<< endl<<endl;
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

    // Enter Choice //SHOULD USE SWITCH CASE , CLASS N OBJECT TO SIMPLYFY UR CODE
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
    
    //Long Chan Seka and Chhin Somalin
    else if (Choice == 2)
    {
    // Key to delete
    cout << "Enter the position to delete: ";
    cin >> position;
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
