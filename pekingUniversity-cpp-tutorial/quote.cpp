#include "main.h"
using std::cout;
using std::cin;
using std::endl;

void swap(int &a, int &b)
{
	/* �Ա�һ��ԭ��c�ķ�ʽ��void swap(int *a, int*b) ����swap(&a, &b) */
	int temp;
	temp = a; a = b; b = temp;
}

int n = 4;
/* ������Ϊ�����ķ���ֵ */
int & SetValue() { return n; }


int main(void)
{
	int n1=1, n2=2;
	cout << n1 << "," << n2 << endl;
	swap(n1, n2);
	cout << n1 << "," << n2 << endl;
	SetValue() = 40;/* ʵ���ϵȼ��� n=40; */
	cout << n << endl;
	cin.ignore();
	return 1;
}