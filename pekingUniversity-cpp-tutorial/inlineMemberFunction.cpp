/*
	* 1. inline + 成员函数
	* 2. 整个函数体定义在类里面
*/
class MyClass1
{
public:
	inline void func1();
	MyClass1();//构造函数，可以有参数，但不能有返回值（void也不行），作用是初始化
	//对象生成时自动调用构造函数，生成后就不能在调用了
	//一个类可以有多个构造函数
	~MyClass1();

private:
	void func2() {}; //注意有个分号
};

MyClass1::MyClass1()
{
}

MyClass1::~MyClass1()
{
}

void MyClass1::func1()
{
}