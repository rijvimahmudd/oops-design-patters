#include <bits/stdc++.h>
using namespace std;

class Employee
{

public:
    virtual void salary() = 0;
    virtual string name() = 0;
    virtual ~Employee() = default;
};

class AndroidDeveloper : public Employee
{

public:
    void salary() override
    {
        cout << "Android Employee salary 50000" << endl;
    }

    string name() override
    {

        return "Android Developer";
    }
};

class IOSDeveloper : public Employee
{

public:
    void salary() override
    {
        cout << "IOS Employee salary 40000" << endl;
    }

    string name() override
    {
        return "IOS Developer";
    }
};

class EmployeeAbstractFactory
{
public:
    virtual Employee *getEmployee() = 0;
};

class EmployeeFactory
{

public:
    static Employee *getEmployee(EmployeeAbstractFactory *factory)
    {
        return factory->getEmployee();
    }
};

class AndroidDeveloperFactory : public EmployeeAbstractFactory
{

public:
    Employee *getEmployee() override
    {
        return new AndroidDeveloper();
    }
};

class IOSDeveloperFactory : public EmployeeAbstractFactory
{

public:
    Employee *getEmployee() override
    {
        return new IOSDeveloper();
    }
};

int main(int argc, char const *argv[])
{

    Employee *emp = EmployeeFactory::getEmployee(new AndroidDeveloperFactory());
    emp->salary();
    cout << emp->name() << endl;

    delete emp;

    emp = EmployeeFactory::getEmployee(new IOSDeveloperFactory());
    emp->salary();
    cout << emp->name() << endl;

    delete emp;
    return 0;
}
