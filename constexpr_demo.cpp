/* 
 * constexpr 关键字将被修饰的函数的调用视作编译时常量，也就是说，不会占用运行时内存 
 * constexpr 有一些限制： 1. 该函数必须有一个非void类型； 2.该函数只能有一个可执行语句，还得是return语句
 * 3.该函数可以有任意可选的using, typedef和空语句
 * 由constexpr修饰的函数被当作内联函数，他们的定义可以放在头文件
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
constexpr int factorial(int n)/* 阶乘 */
{
	return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main(void)
{
	cout << "factorial of 10 is " << factorial(10) << endl;
	cin.ignore();
	return 1;
}