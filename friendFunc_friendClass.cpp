#include "main.h"
/*
	* һ�������Ԫ�������Է��ʸ����˽�г�Ա
*/
//����CCar��
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
friend int MostExpensiveCar(CCar cars[], int total);//������Ԫ����
friend void CDriver::ModifyCar(CCar *pCar);//������Ԫ����
};
int MostExpensiveCar(CCar cars[], int total)
{
	int tmpMax = -1;
	for (int i = 0; i < total; ++i)
	{
		if (cars[i].price > tmpMax)//������˽�г�Աprivate
			tmpMax = cars[i].price;
	}
	return tmpMax;
}
void CDriver::ModifyCar(CCar * pCar)
{
	pCar->price += 1000;//��װ����ֵ
}
class B {
public:
	void function() {};
};
class A {
	friend void B::function();//��Ԫ����
	/*
		* ��һ����ĳ�Ա����(�������졢��������)�������һ�������Ԫ
	*/
};
class C
{
private:
	int a;
friend class D;//����DΪ��Ԫ��
};
class D
{
public:
	C c;
	void ModifyC()
	{
		c.a = 0; //C��D����Ԫ��->C�ĳ�Ա�������Է���D��˽�г�Ա
	}
};
/* 
	* ��Ԫ��
	* C��D����Ԫ�� -> C�ĳ�Ա�������Է���D��˽�г�Ա
	* ��Ԫ��֮��Ĺ�ϵ���ܴ���Ҳ���ܼ̳�
*/
int main()
{
	return 0;
}
