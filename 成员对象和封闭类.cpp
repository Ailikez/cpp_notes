#include "main.h"
/*
	* 成员对象: 一个类的成员是另一个类的对象
	* 包含成员对象的类叫做是封闭类
	* 封闭类构造函数的初始化列表，定义封闭类的构造函数时，添加初始化列表，列表内参数多样
		类名:构造函数(参数表):成员变量1(参数表),成员变量2(参数表),...
		{
			...
		}
	* 当封闭类对象生成时：
		s1.执行所有成员对象的构造函数
		s2.执行封闭类的构造函数
	* 成员对象的构造函数调用顺序：
		1.和对象成员在类中的说明顺序一致
		2.与在成员初始化列表中出现的顺序无关
	* 当封闭类对象消亡时：
		s1.执行封闭类的析构函数
		s2.执行成员对象的析构函数
	* 先构造的后析构，后构造的先析构
*/
class CTyre //轮胎类
{
private:
	int radius;
	int width;
public:
	CTyre(int r, int w) :radius(r), width(w) { PRINT("CTyre constructor called\n"); } //初始化列表方式
	~CTyre() { PRINT("CTyre destructor called\n"); };
};
class CEngine
{
public:
	CEngine() { PRINT("CEngine constructor called\n"); };
	~CEngine() { PRINT("CEngine destructor called\n"); };
private:

};

class CCar 
{
private:
	int price;
	CTyre tyre;
	CEngine engine;
public:
	CCar(int p, int tr, int tw);
	~CCar() { PRINT("CCar destructor called\n"); };
};

CCar::CCar(int p, int tr, int tw) :price(p), tyre(tr, tw){ PRINT("CCar constructor called\n"); };//注意有分号

int main()
{
	CCar car1(20000, 17, 225);
	return 0;
}
/*
//先构造的后析构，后构造的先析构
output:
	CTyre constructor called
	CEngine constructor called
	CCar constructor called
	CCar destructor called
	CEngine destructor called
	CTyre destructor called
*/