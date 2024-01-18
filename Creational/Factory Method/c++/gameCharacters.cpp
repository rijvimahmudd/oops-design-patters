/**
 * Create a game where players can choose different types of characters (e.g., warriors, mages, archers). Implement the Factory Method pattern to create character objects. Each character should have a method like attack() that behaves differently based on the character type.
 */

#include <bits/stdc++.h>
using namespace std;

class Character
{
public:
    virtual void attack() = 0;
    virtual ~Character() = default;
};

class Warrior : public Character
{
public:
    void attack() override
    {
        cout << "Attacking with sword" << endl;
    }
};

class Mage : public Character
{
public:
    void attack() override
    {
        cout << "Attacking with magic" << endl;
    }
};

class Archer : public Character
{
public:
    void attack() override
    {
        cout << "Attacking with bow" << endl;
    }
};

class CharacterFactory
{
public:
    virtual Character *createCharacter() = 0;
    virtual ~CharacterFactory() = default;
};

class WarriorFactory : public CharacterFactory
{
public:
    Character *createCharacter() override
    {
        return new Warrior();
    }
};

class MageFactory : public CharacterFactory
{
public:
    Character *createCharacter() override
    {
        return new Mage();
    }
};

class ArcherFactory : public CharacterFactory
{
public:
    Character *createCharacter() override
    {
        return new Archer();
    }
};

int main(int argc, char const *argv[])
{
    CharacterFactory *warriorFactory = new WarriorFactory();
    Character *warrior = warriorFactory->createCharacter();
    warrior->attack();
    delete warriorFactory;
    delete warrior;

    CharacterFactory *mageFactory = new MageFactory();
    Character *mage = mageFactory->createCharacter();
    mage->attack();
    delete mageFactory;
    delete mage;

    CharacterFactory *archerFactory = new ArcherFactory();
    Character *archer = archerFactory->createCharacter();
    archer->attack();
    delete archerFactory;
    delete archer;

    return 0;
}
