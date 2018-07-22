#include "main.h"
/*
	* 一个类的友元函数可以访问该类的私有成员
*/
//声明CCar类
class CCar;
class CDriver
{
public:
	void ModifyCar(CCar *pCar);
};
class CCar
{
private:
	int price;
friend int MostExpensiveCar(CCar cars[], int total);//声明友元函数
friend void CDriver::ModifyCar(CCar *pCar);//声明友元函数
};
int MostExpensiveCar(CCar cars[], int total)
{
	int tmpMax = -1;
	for (int i = 0; i < total; ++i)
	{
		if (cars[i].price > tmpMax)//访问了私有成员private
			tmpMax = cars[i].price;
	}
	return tmpMax;
}
void CDriver::ModifyCar(CCar * pCar)
{
	pCar->price += 1000;//改装后增值
}
class B {
public:
	void function() {};
};
class A {
	friend void B::function();//友元函数
	/*
		* 将一个类的成员函数(包括构造、析构函数)变成另外一个类的友元
	*/
};
class C
{
private:
	int a;
friend class D;//声明D为友元类
};
class D
{
public:
	C c;
	void ModifyC()
	{
		c.a = 0; //C是D的友元类->C的成员函数可以访问D的私有成员
	}
};
/* 
	* 友元类
	* C是D的友元类 -> C的成员函数可以访问D的私有成员
	* 友元类之间的关系不能传递也不能继承
*/
int main()
{
	return 0;
}
