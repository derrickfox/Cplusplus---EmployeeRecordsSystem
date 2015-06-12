/*
 Program: Final Project
 Description: Employee Records System
 Course: CMSC230 CRN 23267
 Student:  Derrick Fox
 Professor: Greg Grinberg
 Original Due Date: 12/12/14
 */

#include "Department.h"
#include <iomanip>
using namespace std;

// Default constructor for the department object. It creates an empty linked list.
Department::Department():head(0),size(0)
{}

// Searches the list based on Employee's name.
void Department::searchList()
{
    Employee* current = head;
    string name;
    cout << "What is the name of the employee?" << endl;
    cin >> name;
    
    while (current != 0) {
        if (!(current->name == name))
        {
            current = current->next;
        }
        else if (current->name == name)
        {
            cout << current->name << " is " << current->age << " years old " << endl;
            cout << "and makes $" << current->salary << " per year." << endl;
            break;
        }
        else
            cout << "Not found";
    }
}

// Inserts a new Employee object into the Department linked list in order of ID number.
void Department::insert(int ID, const string& name, float salary, int age)
{
    Employee* newNode = new Employee(ID, name, salary, age);
    
    if (head == 0)
    {
        head = newNode;
    }
    else
    {
        Employee* current = head;
        Employee* trail = 0;
        
        while (current != 0)
        {
            if (current->ID >= newNode->ID)
            {
                break;
            }
            else
            {
                trail = current;
                current = current->next;
            }
        }
        if (current == head)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = current;
            trail->next = newNode;
        }
    }
    size++;
}

// Prints the list to the output file in order of ID number.
void Department::printListToFile(ofstream& outFile)
{
    Employee* current = head;
    
    while (current != 0) {
        outFile << current->ID << " " << current->name << " " << current->salary << " " << current->age << endl;
        current = current->next;
    }
}

// Displays list to user in order of ID number.
void Department::printList()
{
    Employee* current = head;
    
    cout << left << setw(4) << "ID# "
         << left << setw(8) << "Name:"
         << left << setw(8) << "Salary:"
         << left << setw(8) << "Age:"
         << endl;
    cout << "----------------------------"<< endl;
    
    while (current != 0) {
        cout << left << setw(4) << current->ID
             << left << setw(8) << current->name
             << left << setw(8) << current->salary
             << left << setw(8) << current->age
             << endl;

        current = current->next;
    }
}

// Displays to the user the sum of all the salaries in this department.
void Department::sumAllSalaries()
{
    Employee* current = head;
    float salarySum = 0;
    
    while (current != 0) {
        salarySum = salarySum + current->salary;
        current = current->next;
    }
    cout << "The total for all salaries is $" << salarySum << endl;
}

// Allows the user to manually input a new Employee object into the linked list.
void Department::addEmployee()
{
    int ident;
    string n;
    float sal;
    int a;
    
    cout << "What is the new ID?" << endl;
    cin >> ident;
    cout << "What is the name?" << endl;
    cin >> n;
    cout << "What is their salary?" << endl;
    cin >> sal;
    cout << "What is their age?" << endl;
    cin >> a;
     
    Employee* newNode = new Employee(ident, n, sal, a);
    
    if (head == 0)
    {
        head = newNode;
    }
    else
    {
        Employee* current = head;
        Employee* trail = 0;
        
        while (current != 0)
        {
            if (current->ID >= newNode->ID)
            {
                break;
            }
            else
            {
                trail = current;
                current = current->next;
            }
        }
        if (current == head)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = current;
            trail->next = newNode;
        }
    }
    size++;
}

// Deletes Employee object from linked list and then re-orders the list in order of ID number.
void Department::deleteEmployee()
{
    int ident;
    int answer;
    cout << "Enter the Employee ID# to delete their record." << endl;
    cin >> ident;
    
    if (head == 0)
    {
        cout << "Employee cannot be deleted from empty list." << endl;
    }
    else
    {
        Employee* curr = head;
        Employee* trail = 0;
        //Case 1 - At head
        while (curr != 0)
        {
            if (curr->ID == ident)
            {
                break;
            }
            else
            {
                trail = curr;
                curr = curr->next;
            }
        }
        
        //Case 2 - Not found
        if (curr == 0)
        {
            cout << "Employee with " << ident << " not found. " << endl;
        }
        else
        {
            // Case 3 - Delete head
            if (head == curr)
            {
                cout << "Are you sure you want to delete " << curr->name << "?" << endl;
                cout << "YES = 1" << endl;
                cout << "NO = 9" << endl;
                cin >> answer;
                
                if (answer == 1)
                {
                    head = head->next;
                }
                else
                    return;

                //head = head->next;
            }
            
            // Case 4 - Delete beyond head
            else
            {
                cout << "Are you sure you want to delete " << curr->name << "?" << endl;
                cout << "YES = 1" << endl;
                cout << "NO = 9" << endl;
                cin >> answer;
                
                if (answer == 1)
                {
                    trail->next = curr->next;
                }
                else
                    return;
                //trail->next = curr->next;
            }
        }
        delete curr;
        size--;
    }
}

// Allows the user to update an existing Employee object/record.
void Department::updateEmployee()
{
    Employee* current = head;
    string name;
    string newName;
    int newID;
    int newAge;
    int newSalary;
    cout << "What is the name of the employee?" << endl;
    cin >> name;
    int answer;
    
    while (current != 0) {
        if (!(current->name == name))
        {
            current = current->next;
        }
        else if (current->name == name)
        {
            cout << "Are you sure you want to update " << current->name << "?" << endl;
            cout << "Update Name = 1" << endl;
            cout << "Update Salary = 2" << endl;
            cout << "Update Age = 3" << endl;
            cout << "Update ID# = 4" << endl;
            cout << "EXIT = 9" << endl;
            cin >> answer;
            
            switch (answer) {
                case 1:
                    cout << "Enter " << current->name << "'s new name." << endl;
                    cin >> newName;
                    current->name = newName;
                    break;
                case 2:
                    cout << "Enter " << current->name << "'s new salary." << endl;
                    cin >> newSalary;
                    current->salary = newSalary;
                    break;
                case 3:
                    cout << "Enter " << current->name << "'s new age." << endl;
                    cin >> newAge;
                    current->age = newAge;
                    break;
                case 4:
                    cout << "Enter " << current->name << "'s new ID#." << endl;
                    cin >> newID;
                    current->ID = newID;
                    break;
                default:
                    break;
            }
            break;
        }
        else
            cout << "Not found";
    }
    sortByID();
}

// Sorts the list by Employee ID number.
void Department::sortByID()
{
    Employee *curr = NULL;
    Employee *trail = NULL;
    Employee *temp = NULL;
    
    for(int i = 0; i<size; ++i)
    {
        curr = trail = head;
        while (curr->next != NULL)
        {
            if (curr->ID > curr->next->ID)
            {
                temp = curr->next;
                curr->next = curr->next->next;
                temp->next = curr;
                
                if(curr == head)
                    head = trail = temp;
                else
                    trail->next = temp;
                curr = temp;
            }
            trail = curr;
            curr = curr->next;
        }
    }
}











