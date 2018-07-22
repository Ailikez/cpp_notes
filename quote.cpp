#include "main.h"
using std::cout;
using std::cin;
using std::endl;

void swap(int &a, int &b)
{
	/* 对比一下原来c的方式，void swap(int *a, int*b) 调用swap(&a, &b) */
	int temp;
	temp = a; a = b; b = temp;
}

int n = 4;
/* 引用作为函数的返回值 */
int & SetValue() { return n; }


int main(void)
{
	int n1=1, n2=2;
	cout << n1 << "," << n2 << endl;
	swap(n1, n2);
	cout << n1 << "," << n2 << endl;
	SetValue() = 40;/* 实际上等价于 n=40; */
	cout << n << endl;
	cin.ignore();
	return 1;
}