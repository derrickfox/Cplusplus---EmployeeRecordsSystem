/*
Program: Final Project
Description: Employee Records System
Course: CMSC230 CRN 23267
Student:  Derrick Fox
Professor: Greg Grinberg
Original Due Date: 12/12/14
*/
 
#include "Department.h"
#include <iostream>
#include <fstream>
using namespace std;

// Function for controlling the user-menu.
void CommandIt();

int main()
{
    // File streams for input and output files.
    ofstream outFile;
    outFile.open("Group.dat");
    
    ifstream inFile;
    inFile.open("Input.dat");
    
    // Declare a department object which acts like a linked list.
    Department* department = new Department();
    
    // Variables to hold the instance variables of the Employee object.
    int ID;
    string name;
    float salary;
    int age;
    string systemCommand = "";
    int commandInt;
    
    // While-loop to read-in Employee data while the end of the file is not reached.
    while (!inFile.eof())
    {
        inFile >> ID >> name >> salary >> age;
        department->insert(ID, name, salary, age);
    }
    
    cout << "Employee Records System:" << endl;
    
    CommandIt();
    cin >> commandInt;
    
    // User selection menu.
    while (commandInt != 475848)
    {
        switch (commandInt)
        {
            case 0:
                department->printListToFile(outFile);
                exit(0);
                break;
            case 1:
                department->addEmployee();
                CommandIt();
                cin >> commandInt;
                cout << endl;
                break;
            case 2:
                department->deleteEmployee();
                CommandIt();
                cin >> commandInt;
                cout << endl;
                break;
            case 3:
                department->updateEmployee();
                CommandIt();
                cin >> commandInt;
                cout << endl;
                break;
            case 4:
                department->printList();
                CommandIt();
                cin >> commandInt;
                cout << endl;
                break;
            case 5:
                department->sumAllSalaries();
                CommandIt();
                cin >> commandInt;
                cout << endl;
                break;
            case 6:
                department->searchList();
                CommandIt();
                cin >> commandInt;
                cout << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}



void CommandIt()
{
    cout << endl;
    cout << "Add Employee enter 1" << endl;
    cout << "Delete Employee enter 2"<< endl;
    cout << "Update Employee enter 3" << endl;
    cout << "Display All Employees enter 4" << endl;
    cout << "Display Total Salaries enter 5"<< endl;
    cout << "Search for Employee enter 6"<< endl;
    cout << "To Quit enter 0" << endl;
    cout << endl;
}
















