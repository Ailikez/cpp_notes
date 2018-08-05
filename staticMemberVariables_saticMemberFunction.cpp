#include "main.h"
/*
	* 普通成员变量每个对象有自己各自的一份，静态成员变量一共就一份，所有对象共享
	* sizeof运算符不会将静态成员变量纳入计算
*/
/*
	* 普通成员函数必须具体作用于某个对象，静态成员函数并不具体作用于某个对象
*/
/*
	* 静态成员(变量/函数)不需要通过对象就可以访问到
	* 1.类名::静态成员名
	* 2.对象名.静态成员名(注意，并不是作用在对象上，只是一种写法而已)
	* 3.指针->静态成员名
	* 4.引用.静态成员名
	* 静态变量本质上就是全局变量，哪怕一个对象都不存在了，类的静态变量还是存在
	* 意义： 将和某些类紧密相关的全局变量和函数写到类里面，看上去像是一个整体，便于理解和维护
*/
class CRectangle
{
public:
	CRectangle(int _w, int _h);
	CRectangle(int _w);
	~CRectangle();
	static void PrintTotal();//静态成员函数
private:
	int w, h;
	/*
		* 我需要随时知道矩形总数和总面积，所以用全局变量来记录，写到类里面就变静态成员了
	*/
	static int nTotalAera;//静态成员变量
	static int nTotalNumber;
};

CRectangle::CRectangle(int _w, int _h)
{
	w = _w, h = _h;
	nTotalAera += w * h;
	nTotalNumber ++;
	PRINT("Constructor called\n");
	/*注意此处有严重BUG*/
	/*不是所有对象都用此函数构建*/
	/*调用复制构造函数生成临时的隐藏的对象时不会调用这个函数*/
}
//复制构造函数要自己重写才会解决BUG
CRectangle::CRectangle(int _w)//类型转换构造函数
{
	PRINT("Type transform Constructor called\n");
	w = _w, h = 3;
	/*这里要对应增加全局变量才ok*/
}
CRectangle::~CRectangle()
{
	nTotalAera -= w * h;
	nTotalNumber--;
	PRINT("Destructor called\n");
	/* 注意此处有严重BUG */
	/* 调用复制构造函数生成临时的隐藏的对象消亡时会调用这个函数，使变量平白无故减少 */
	/* 调用一个以CRectangle对象为函数参数的函数时 */
	/* 调用一个以CRectangle对象为函数返回值时 */
	/* 类型转换函数生成的临时对象消亡时 */
}
void CRectangle::PrintTotal()
{
	/* 在静态成员函数中不能访问非静态成员变量也不能调用非静态成员函数，因为静态成员函数不是针对某个对象的 */
	PRINT("%d,%d\n", nTotalNumber, nTotalAera);
}
/* 必须在定义类的文件中对静态成员变量进行一次声明或者初始化否则编译能通过，链接不能通过 */
int CRectangle::nTotalNumber = 0;
int CRectangle::nTotalAera = 0;

int main()
{
	CRectangle r1(3, 3), r2(2, 2);
	//CRectangle::PrintTotal();
	//{CRectangle r3(4,4); CRectangle::PrintTotal();}
	CRectangle::PrintTotal();
	r1 = 3;
	CRectangle::PrintTotal();
	r1.PrintTotal();
	return 0;
}