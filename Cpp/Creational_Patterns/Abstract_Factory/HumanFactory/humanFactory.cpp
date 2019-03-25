#include <iostream>

using namespace std;

class Soldier 
{
public:
    virtual void shoot() = 0;
};

class Archer: public Soldier 
{
public:
    void shoot() {
        std::cout << "Archer shoot" << std::endl;
    }
};

class Rider : public Soldier 
{
public:
    void shoot() {
        std::cout << "Rider shoot" << std::endl;
    }
};

class AbstractFactory 
{
public:
    virtual Soldier* createArcher() = 0;
    virtual Soldier* createRider() = 0;
};

class OrcFactory : public AbstractFactory 
{
public:
    Soldier* createArcher()
    {
        return new Archer();
    }

    Soldier* createRider()
    {
        return new Rider();
    }
};

class HumanFactory : public AbstractFactory 
{
public:
    Soldier *createArcher()
    {
        return new Archer();
    }

    Soldier *createRider()
    {
        return new Rider();
    }
};

class Game 
{
public:
    AbstractFactory* factory;
    Game(AbstractFactory* factory):factory(factory){};
};


int main()
{
    Game* game = new Game(new HumanFactory);
    Archer* HumanArcher = static_cast<Archer*>(game->factory->createArcher());
    Rider* humanRider = static_cast<Rider*>(game->factory->createRider());

    HumanArcher->shoot();
    humanRider->shoot();

    return 0;
}