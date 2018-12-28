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
    Animal(int age): age(age) { GetAge(); std::cout << "class Animal constructor called...\n"; }
    virtual ~Animal() { std::cout << "class animal destructor called...\n"; }
    virtual int GetAge() { std::cout << "Age :" << age << std::endl; return age; }
    int age;
};

class Horse : public Animal
{
public:
    Horse(int age): Animal(age) {  std::cout << "class Horse constructor called...\n"; }
    virtual ~Horse() { std::cout << "class Horse destructor called...\n";}
    virtual void Whinny() const { std::cout << "Whinny!... "; }
    int GetAge() { std::cout << "Horse Age :" << age << std::endl; return age; }
	int horseSize;
};


class Bird : public Animal
{
public:
    Bird(int age): Animal(age) { std::cout << "class Bird constructor called...\n"; }
    virtual ~Bird() { std::cout << "class Bird destructor called...\n"; }
    virtual void Fly() const { std::cout << "i believe i can fly!"; }
	int birdSize;
};

int main(int argc, const char * argv[])
{
    Animal *horse = new Horse(10);
    Animal *birds = new Bird(1);
    
    
    horse->GetAge();
    birds->GetAge();
    
   
    std::cout << "Horse class size -> " << sizeof(Horse) << std::endl;
    std::cout << "Bird class size -> " << sizeof(Bird) << std::endl;
    std::cout << "Animal class size -> " << sizeof(Animal) << std::endl;
    
    horse = new Horse(1);
    Horse *newHorse = dynamic_cast<Horse *>(horse);
    newHorse->GetAge();
    newHorse->Whinny();
    
    /*
     1.R// El espacio dependerá de las funciones virtuales declaradas en la clase base mas un tamaño extra
     que es para el miembro oculto llamado vptr que es un puntero que apunta a vtable. Este ultimo valor
     depende de la arquitectura del computador (32, 64).

	 C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.15.26726\bin\Hostx64\x64\cl.exe" main.cpp /nologo /d1reportSingleClassLayoutAnimal

	 class Animal    size(16):
		+---
 0      | {vfptr}
 8      | age
		| <alignment member> (size=4)
		+---

Animal::$vftable@:
		| &Animal_meta
		|  0
 0      | &Animal::{dtor}
 1      | &Animal::GetAge
     

 class Horse     size(24):
		+---
 0      | +--- (base class Animal)
 0      | | {vfptr}
 8      | | age
		| | <alignment member> (size=4)
		| +---
16      | horseSize
		| <alignment member> (size=4)
		+---

Horse::$vftable@:
		| &Horse_meta
		|  0
 0      | &Horse::{dtor}
 1      | &Animal::GetAge
 2      | &Horse::Whinny


 class Bird      size(24):
		+---
 0      | +--- (base class Animal)
 0      | | {vfptr}
 8      | | age
		| | <alignment member> (size=4)
		| +---
16      | birdSize
		| <alignment member> (size=4)
		+---

Bird::$vftable@:
		| &Bird_meta
		|  0
 0      | &Bird::{dtor}
 1      | &Animal::GetAge
 2      | &Bird::Fly
     
     
     2.R// las tablas de funciones virtuales están almacenadas en la memoria. En algunos compiladores las tablas de funciones virtuales se almacenan en la memoria de solo lectura, lo que evita que sean modificadas.
     
     3. R// Depende del procesador, puede aumentar en 4 bytes si es de 32, o en 8 bytes en una de 64.
     
     4. R//
     Age :10
     class Animal constructor called...
     class Horse constructor called...
     
     Como se ve en los logs primero se llama el constructor de la clase base y el método virtual que se esta ejecutando 'GetAge()' es el de la clase base y no de la clase derivada.
     
     5. R// El compilador en una función virtual debe acceder al puntero vfptr para buscar la referencia de esa función y poder llamarla.
     En una función no virtual solamente debe encontrar la posición de la función y llamarla.

     */
    
    
    
    return 0;
}
