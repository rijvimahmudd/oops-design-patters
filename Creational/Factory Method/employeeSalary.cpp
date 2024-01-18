

#include <bits/stdc++.h>
using namespace std;

class Employee
{

public:
    virtual int calculateSalary() = 0;
};

class AndroidDeveloper : public Employee
{

public:
    int calculateSalary() override
    {
        cout << "Android Employee salary " << endl;
        return 50000;
    }
};

class IOSDeveloper : public Employee
{

public:
    int calculateSalary() override
    {
        cout << "IOS Employee salary " << endl;
        return 50000;
    }
};

// concrete class / subclass

class EmployeeFactory
{
public:
    static Employee *getEmployee(string empType)
    {
        if (empType == "AndroidDeveloper")
        {
            return new AndroidDeveloper();
        }
        else if (empType == "IOSDeveloper")
        {
            return new IOSDeveloper();
        }
        else
        {
            return nullptr;
        }
    }
};

int main(int argc, char const *argv[])
{
    Employee *emp = EmployeeFactory::getEmployee("AndroidDeveloper");
    emp->calculateSalary();

    delete emp;

    Employee *emp1 = EmployeeFactory::getEmployee("IOSDeveloper");
    emp1->calculateSalary();

    delete emp1;
    return 0;
}
