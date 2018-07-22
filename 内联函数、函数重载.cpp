#include "main.h"

/*
	* 函数调用是有开销的，在函数比较简单但又需要多次重复掉用时，使用内联函数来减小多次调用带来的额外开销
	* 编译器将内敛函数代码插入到内联函数语句调用处避免调用函数带来的开销
*/
/* 
	* 函数重载: 一个或多个函数名字相同，但是参数个数或类型不同。
	* 
*/
inline int Max(int a, int b) 
{
	if (a > b) return a;
	return b;
}

int Max(double f1, double f2) {}
int Max(int f1, double f2) {}
int Max(int n1, int n2, int n3) {}


void main(void)
{

}