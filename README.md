# ProjectN15
Ejercicios UTAD # 15


```bat
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
```
