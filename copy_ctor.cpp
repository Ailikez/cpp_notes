/*
	* 只有一个参数，即对同类对象的引用，形如 X::X( X& ) 或 X::X(const X &)
	* 没定义编译器默认生成，默认复制构造函数完成复制功能
	* 不允许X::X(X)这种形式，括号里必须是引用
	* 什么时候起作用？
		* 1.用一个对象去初始化另外一个同类的对象时。
			Complex c2(c1); 等价于 Complex c2 = c1;//初始化，非赋值
		* 2.某个函数的形参时类A的对象，该函数被调用时，类A的复制构造函数也会被调用来初始化形参。
			void Func(A a1){}
			void main(){ A a2; Func(a2); }
		* 3.函数返回值是类A的对象，函数返回时会调用。

	* 为啥自己要写复制构造函数
		？
*/
#include "main.h"
using std::cout;
using std::cin;
class Complex
{
public:
	double real, imag;
};

Complex c1;//调用缺省无参的构造函数
Complex c2(c1);//调用缺省的复制构造函数，将c2初始化成和c1一样

class Complex2
{
public:
	double real, imag;
	Complex2(double _r, double _i) { real = _r; imag = _i; }
	Complex2(const Complex2 &c)
	{
		real = c.real;
		imag = c.imag;
		cout << "copy completed" << endl;
	}
};
Complex2 c3(1.2, 3.4);//调用缺省无参的构造函数
Complex2 c4(c3);//调用缺省的复制构造函数，将c2初始化成和c1一样
void main() { cin.ignore(); }