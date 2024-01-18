/*
    Develop a transportation management system that handles different modes of transportation (e.g., trucks, ships, airplanes). Use the Factory Method pattern to create transportation objects. Each mode of transportation should have a method like transportCargo().
*/

#include <bits/stdc++.h>
using namespace std;

class Transportation
{
public:
    virtual void transportCargo() const = 0;
    virtual ~Transportation() = default;
};

class Truck : public Transportation
{
public:
    void transportCargo() const override
    {
        cout << "Truck is being transported" << endl;
    }
};

class Ship : public Transportation
{
public:
    void transportCargo() const override
    {
        cout << "Ship is being transported" << endl;
    }
};

class Airplane : public Transportation
{
public:
    void transportCargo() const override
    {
        cout << "Airplane is being transported" << endl;
    }
};

class TransportationFactory
{
public:
    virtual Transportation *createTransportation() = 0;
    virtual ~TransportationFactory() = default;
};

class TruckFactory : public TransportationFactory
{
public:
    Transportation *createTransportation() override
    {
        return new Truck();
    }
};

class ShipFactory : public TransportationFactory
{
public:
    Transportation *createTransportation() override
    {
        return new Ship();
    }
};

class AirplaneFactory : public TransportationFactory
{
public:
    Transportation *createTransportation() override
    {
        return new Airplane();
    }
};

int main(int argc, char const *argv[])
{
    TransportationFactory *truckFactory = new TruckFactory();
    Transportation *truck = truckFactory->createTransportation();
    truck->transportCargo();
    delete truck;
    delete truckFactory;

    TransportationFactory *shipFactory = new ShipFactory();
    Transportation *ship = shipFactory->createTransportation();
    ship->transportCargo();
    delete ship;
    delete shipFactory;

    TransportationFactory *airplaneFactory = new AirplaneFactory();
    Transportation *airplane = airplaneFactory->createTransportation();
    airplane->transportCargo();
    delete airplane;
    delete airplaneFactory;

    return 0;
}
