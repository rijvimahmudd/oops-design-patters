// also known as virtual constructor

/**
 ** Factory Method is a creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.

 * https://refactoring.guru/design-patterns/factory-method
 *
    * Imagine that you’re creating a logistics management application. The first version of your app can only handle transportation by trucks, so the bulk of your code lives inside the Truck class.

    After a while, your app becomes pretty popular. Each day you receive dozens of requests from sea transportation companies to incorporate sea logistics into the app.

    Great news, right? But how about the code? At present, most of your code is coupled to the Truck class. Adding Ships into the app would require making changes to the entire codebase. Moreover, if later you decide to add another type of transportation to the app, you will probably need to make all of these changes again.

    As a result, you will end up with pretty nasty code, riddled with conditionals that switch the app’s behavior depending on the class of transportation objects.
 *
 *
 *
*/

/**
 * Solution
    The Factory Method pattern suggests that you replace direct object construction calls (using the new operator) with calls to a special factory method. Don’t worry: the objects are still created via the new operator, but it’s being called from within the factory method. Objects returned by a factory method are often referred to as products.
*/

#include <bits/stdc++.h>
using namespace std;

// Product interface
// This is a abstract class
class Transport
{
public:
    virtual void deliver() const = 0;
    virtual ~Transport() = default;
};

// Concrete Product
class Truck : public Transport
{
public:
    void deliver() const override
    {
        cout << "Delivering by truck" << endl;
    }
};

class Ship : public Transport
{
public:
    void deliver() const override
    {
        cout << "Delivering by Ship" << endl;
    }
};

// creator interface
// this is a abstract class
class Logistics
{
public:
    virtual Transport *createTransport() const = 0;
    virtual ~Logistics() = default;
};

// concrete creator
class RoadLogistics : public Logistics
{
public:
    Transport *createTransport() const override
    {
        return new Truck();
    }
};

class SeaLogistics : public Logistics
{
public:
    Transport *createTransport() const override
    {
        return new Ship();
    }
};

int main(int argc, char const *argv[])
{
    // client code
    Logistics *roadLogistics = new RoadLogistics();
    Transport *truck = roadLogistics->createTransport();
    truck->deliver();
    delete truck;
    delete roadLogistics;

    Logistics *seaLogistics = new SeaLogistics();
    Transport *ship = seaLogistics->createTransport();
    ship->deliver();
    delete ship;
    delete seaLogistics;

    return 0;
}
