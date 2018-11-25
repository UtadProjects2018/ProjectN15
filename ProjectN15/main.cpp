//
//  main.cpp
//  ProjectN15
//
//  Created by pc-laptop on 11/24/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <iostream>

class Animal
{
public:
    Animal(int age): m_Age(age) { std::cout << "class Animal constructor called...\n"; }
    virtual ~Animal() { std::cout << "class animal destructor called...\n"; }
    virtual int GetAge() const { std::cout << "Age :" << m_Age << std::endl; return m_Age; }
    virtual void SetAge(int age) { m_Age = age; }
private:
    int m_Age;
};

class Horse : public Animal
{
public:
    Horse(int age): Animal(age) {  std::cout << "class Horse constructor called...\n"; }
    virtual ~Horse() { std::cout << "class Horse destructor called...\n";}
    virtual void Whinny() const { std::cout << "Whinny!... "; }
};


class Bird : public Animal
{
public:
    Bird(int age): Animal(age) { std::cout << "class Bird constructor called...\n"; }
    virtual ~Bird() { std::cout << "class Bird destructor called...\n"; }
    void Fly() const { std::cout << "i believe i can fly!"; }
};

int main(int argc, const char * argv[])
{
    Animal *horse = new Horse(10);
    Animal *birds = new Bird(1);
    
    //Called virtual methods
    horse->GetAge();
    birds->GetAge();
    
    
    int houseClassSize = sizeof(Horse);
    int birdClassSize = sizeof(Bird);
    int animalClassSize = sizeof(Animal);
    std::cout << "Horse class size -> " << houseClassSize << std::endl;
    std::cout << "Bird class size -> " << birdClassSize << std::endl;
    std::cout << "Animal class size -> " << animalClassSize << std::endl;
    
    horse = new Horse(1);
    Horse *newHorse = dynamic_cast<Horse *>(horse);
    Bird *newBird = dynamic_cast<Bird *>(horse);
    newHorse->GetAge();
    
    if (!newBird)
    {
      std::cout << "Bird class is nil -> " << std::endl;
    }
    
    delete horse;
    delete birds;
    
    return 0;
}
