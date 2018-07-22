/*
	* 实现类型自动转换
	* 只有一个参数
	* 不是复制构造参数
	* 编译系统自动调用->转换构造函数->建立一个临时变量/临时对象
*/
#include "main.h"
class Complex
{
public:
	double
		real, imag;
	Complex(double r, double i);
	Complex(int i);//类型转换构造函数

private:

};

Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}
Complex::Complex(int i)//类型转换构造函数
{
	cout << "Type transform Constructor called" << endl;
	real = i;
	imag = 0;
}
int main() {
	Complex c1(7, 8);
	Complex c2 = 12;
	c1 = 9;//9被转换成临时Complex对象
	cout << c1.real << "," << c1.imag;
	cin.ignore();
	return 0;
}
/*
输出：
Type transform Constructor called
Type transform Constructor called
9,0
*/