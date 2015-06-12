/*
 Program: Final Project
 Description: Employee Records System
 Course: CMSC230 CRN 23267
 Student:  Derrick Fox
 Professor: Greg Grinberg
 Original Due Date: 12/12/14
 */

#ifndef __DFox_Final_Project__Department__
#define __DFox_Final_Project__Department__

#include <stdio.h>
#include "Employee.h"
#include <fstream>

// Class definition for Department which acts as a linked list. 
class Department
{
public:
    Department();
    void printListToFile(std::ofstream& outFile);
    void insert(int ID, const std::string& name, float salary, int age);
    void searchList();
    void printList();
    void sumAllSalaries();
    void addEmployee();
    void deleteEmployee();
    void updateEmployee();
    void sortByID();
    
private:
    Employee* head;
    std::string manager;
    int size;
};

#endif /* defined(__DFox_Final_Project__Department__) */
