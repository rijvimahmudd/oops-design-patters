/*
    Create a zoo simulation where different types of animals (e.g., lions, elephants, monkeys) are present. Implement the Factory Method pattern to create animal objects. Define a common interface for all animals with a method like makeSound().

*/

#include <bits/stdc++.h>
using namespace std;

class Animal
{

public:
    virtual void makeSound() const = 0;
    virtual ~Animal() = default;
};

class Lion : public Animal
{

public:
    void makeSound() const override
    {
        cout << "Roar" << endl;
    }
};

class Elephant : public Animal
{

public:
    void makeSound() const override
    {
        cout << "Trill" << endl;
    }
};

class Monkey : public Animal
{

public:
    void makeSound() const override
    {
        cout << "Squeak" << endl;
    }
};

class AnimalFactory
{
public:
    virtual Animal *createAnimal() const = 0;
    virtual ~AnimalFactory() = default;
};

class LionFactory : public AnimalFactory
{

public:
    Animal *createAnimal() const override
    {
        return new Lion();
    }
};

class ElephantFactory : public AnimalFactory
{
public:
    Animal *createAnimal() const override
    {
        return new Elephant();
    }
};

class MonkeyFactory : public AnimalFactory
{
public:
    Animal *createAnimal() const override
    {
        return new Monkey();
    }
};

int main(int argc, char const *argv[])
{
    AnimalFactory *lionFactory = new LionFactory();
    Animal *lion = lionFactory->createAnimal();
    lion->makeSound();
    delete lion;
    delete lionFactory;

    AnimalFactory *elephantFactory = new ElephantFactory();
    Animal *elephant = elephantFactory->createAnimal();
    elephant->makeSound();
    delete elephant;
    delete elephantFactory;

    AnimalFactory *monkeyFactory = new MonkeyFactory();
    Animal *monkey = monkeyFactory->createAnimal();
    monkey->makeSound();
    delete monkey;
    delete monkeyFactory;

    return 0;
}
