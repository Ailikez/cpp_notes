/*
	* destructor，成员函数的一种，名字与类名相同，前面加~，没有参数和返回值，一个类最多一个
	* 对象消亡时自动调用，对象消亡前做下善后，释放使用的空间等等
	* 没写的的话编译器自动生成，但是不涉及释放用户申请的内存释放等清理工作
	* delete new出的类的对象也会导致destructor被调用
*/
#include "main.h"

class String
{
public:
	String();
	~String();

private:
	char *p;
};

String::String()
{
	p = new char[10];
}

String::~String()
{
	cout << "destructor called" << endl;
	delete[] p;
}

class Demo
{
public:
	Demo(int i);
	~Demo();

private:
	int id;
};

Demo::Demo(int i)
{
	id = i;
	//cout << "id=" << id << " Constructed!" << endl;
	PRINT("id=%d Constructed!\n", id);
}

Demo::~Demo()
{
	//cout << "id=" << id << " Destructed!" << endl;
	PRINT("id=%d Destructed!\n", id);
}
Demo d1(1);
void Func()
{
	PRINT("Func called\n");
	static Demo d2(2);
	Demo d3(3);
	PRINT("Func called end\n");
}
int main(void) 
{
	Demo d4(4);
	d4 = 6;//注意这里会输出啥
	PRINT("main\n");
	{Demo d5(5);}//构建后马上会被析构，离开作用域后消亡
	Func();
	PRINT("main end\n");
	return 0;
	/* 先被构造的对象最后析构掉 */
}
/*
id=1 Constructed!
id=4 Constructed!
id=6 Constructed!
id=6 Destructed!
main
id=5 Constructed!
id=5 Destructed!
id=2 Constructed!
id=3 Constructed!
Func called
id=3 Destructed!
main end
id=6 Destructed!
id=2 Destructed!
id=1 Destructed!
*/