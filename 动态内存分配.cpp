#include "main.h"
/*
new的用法
	1.第一种用法，分配一个变量；
	P = new T;
	T是任意类型名，P是类型为T*的指针。
	动态分配出一片大小为sizeof(T)字节的内存，并将其起始地址赋给P
	如	int *pn;
		pn = new int;
		*pn = 5;

	2.第二种用法，分配一个数组；
	P = new T[N];
	T是任意类型名，P是类型为T*的指针，N为要分配的数组元素的个数，可以是整形表达式哦。
	动态分配出一片大小为N*sizeof(T)字节的内存，并将其起始地址赋给P
	如	int *pn;
		int i = 5;
		pn = new int[i*20];
		pn[0] = 20;
		pn[100] = 300; //该语句编译没问题，运行会发生越界
	3.new运算符的返回值类型
	new T;
	new T[n];
	返回值都是 T* 类型
*/
/*
delete的用法
	1.用new动态分配的内存，一定要用delete释放
	delete p; //p为指向new分配的空间的指针
	如	int *p = new int;
		*p = 5;
		delete p;
		delete p; //导致异常，同一片空间不能delete多次
	2.delete数组
	delete [] p; //p为指向new分配的空间的指针

*/
int main(void)
{

	return 0;
}