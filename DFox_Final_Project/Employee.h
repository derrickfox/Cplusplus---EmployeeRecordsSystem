/*
 Program: Final Project
 Description: Employee Records System
 Course: CMSC230 CRN 23267
 Student:  Derrick Fox
 Professor: Greg Grinberg
 Original Due Date: 12/12/14
 */

#ifndef __DFox_Final_Project__Employee__
#define __DFox_Final_Project__Employee__

#include <stdio.h>
#include <iostream>
#include <string>

// Employee class definition.
class Employee
{
    friend class Department;
    
public:
    Employee(int ID, std::string name, float salary, int age);
    
private:
    int ID;
    std::string name;
    float salary;
    int age;
    Employee* next;
};

#endif /* defined(__DFox_Final_Project__Employee__) */
