#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
using namespace std;
//Наследование - механизм способный перенимать свойства одного класса в другой и добовлять свои собственные

//class Point
//{
//
//protected:
//	int x;
//	int y;
//public:
//	Point()
//	{
//		x = 0;
//		y = 0;
//	}
//
//	int& GetX()
//	{
//		return x;
//	}
//
//	int& GetY()
//	{
//		return y;
//	}
//
//};
//class MyWindows :public Point
//{
//	int Width;
//	int Height;
//public:
//	MyWindows(int width, int height)
//	{
//		Width = width;
//		Height = height;
//	}
//
//	int& GetWidth()
//	{
//		return Width;
//	}
//
//	int& GetHeight()
//	{
//		return Height;
//	}
//
//	void MoveX(int Dx)
//	{
//		x += Dx;
//	}
//
//	void MoveY(int Dy)
//	{
//		y += Dy;
//	}
//
//	void Show()
//	{
//		cout << "X= " << x << "\nY= " << y << "\n\n";
//		cout << "Width= " << Width << "\nHeight= " << Height << "\n\n";
//	}
//};

/*
* Класс-родитель
* template<class T>
* class Pair
* {
*	T a;
*	T b;
* public:
*	Pair(T t1,Tt2)
*   ...
* }
* Конструктор
* template<class T>
* Pair<T>::Pair(T t1,T t2):a(t1),b(t2)
* {}
* 
* Класс-потомок
* template<class T>
* class Trio:public Pair<T>
* {
*	T c;
* public:
*	Trio(T t1,T t2,T t3);
*	...
* }
* Trio<T>::Trio(T t1,T t2,T t3):Pair<T>(t1,t2),c(t3);
* {}
* 
*/

/*
* Виртуальные функции
* 
* A object A;
* B object B;
* C object C;
* 
* A* point_to_object;
* point_to_object = &object_C;
* point_to_object=&object_B;
* point_to_object->v_Function();
* 
* Class A
* {
*public:
*		virtual void v_Function();
* }
* 
* class B: public A
* {
* public:
*	virtual void v_Function(void); замещающая функция   нельзя написать virtual int v_Function(void)-тип данных должен быть один и  virtual void v_Function(int) тоже нельзя это уже другие функции
* 
* }
* 
* 
* class Weapon
* {
*	public:
*	... Тут будут данные-члены, которыми может описываться, например, как толщина дубины, так и количество гранат в гранатомёте, и т.д
*	
*		virtual void Use1(void); обычно-левая кнопка мыши
*		virtual void Use2(void); обычно-правая кнопка мыши
*	...	Тут будут ещё какие-то данные-члены и методы
* }
* 
* Weapon *Arms[10];-Массив указателей на объект типа Weapon
* int TypeWeapon;
* if("Нажата левая кнопка мыши") Arms[TypeOfWeapon]->Use1();
* else Arms[TypeOfWeapon]->Use2();
* 
* class A
{
* public://Чисто виртуальная функция
*	virtual void v_Function()=0;
};
* 
* 
* 
* 
*/

class Animal
{

public:
	char Title[20];
	Animal(const char* t)
	{
		strcpy(Title, t);
	}

	virtual void speak() = 0;
};

class Frog :public Animal
{

public:
	Frog(const char* Title) :Animal(Title) {};
	virtual void speak()
	{
		cout << Title << " Say " << "\ 'kva-kva\'\n";
	}
};

class Dog :public Animal
{

public:
	Dog(const char* Title) :Animal(Title) {};
	virtual void speak()
	{
		cout << Title << " Say " << "\ 'gav-gav\'\n";
	}
};

class Cat :public Animal
{

public:
	Cat(const char* Title) :Animal(Title) {};
	virtual void speak()
	{
		cout << Title << " Say " << "\ 'may-may\'\n";
	}
};

class Lion :public Cat
{

public:

	Lion(const char* Title) :Cat(Title) {};

	virtual void speak()
	{
		cout << Title << " Say " << "\'rrr-rrr\'\n";
	}

	virtual void speak1(int When)
	{
		cout << Title << " Say " << "\ 'rrr-rrr\'\n";
	}
};

int main()
{
	Animal* animals[4] = { new Dog("Bob"),new Cat("Boris"),new Frog("Vasia"),new Lion("Simba")};
	//for (int i = 0; i < 4; i++)
	//{
	//	animals[i]->speak();
	//}


	return 0;
}