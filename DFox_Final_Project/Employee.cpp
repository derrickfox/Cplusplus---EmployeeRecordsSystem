/*
 Program: Final Project
 Description: Employee Records System
 Course: CMSC230 CRN 23267
 Student:  Derrick Fox
 Professor: Greg Grinberg
 Original Due Date: 12/12/14
 */

#include "Employee.h"
using namespace std;

// Structure for the Employee class.
Employee::Employee(int i, string n, float s, int a): next(NULL)
{
    ID = i;
    name = n;
    salary = s;
    age = a;
}